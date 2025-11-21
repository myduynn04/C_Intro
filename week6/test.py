import json
import glob
import argparse
import re
import ast
from pathlib import Path

def parse_rc(rc_raw: str):
    """
    Trả về dict đã parse từ response_content (kiểu string chứa Python dict).
    Ưu tiên ast.literal_eval; fallback sửa tối thiểu để json.loads.
    """
    try:
        rc = ast.literal_eval(rc_raw)
        if isinstance(rc, dict):
            return rc
    except Exception:
        pass

    # Fallback: chuyển tối thiểu về JSON hợp lệ
    s = rc_raw.replace("\\'", "'").replace('\\"', '"')
    s = s.replace("'", '"')
    s = s.replace(": True", ": true").replace(": False", ": false").replace(": None", ": null")
    return json.loads(s)

def parse_line(line: str):
    """
    Trả về tuple (ok, rc_dict) nếu parse được response_content; ngược lại (False, reason)
    """
    try:
        root = json.loads(line)
    except Exception as e:
        return (False, f"root json error: {e}")

    rec = root.get("record") or root.get("event", {}).get("record")
    if not rec:
        return (False, "no record")

    msg_raw = rec.get("message")
    if not msg_raw:
        return (False, "no record.message")

    try:
        msg = json.loads(msg_raw)
    except Exception as e:
        return (False, f"message json error: {e}")

    rc_raw = msg.get("response_content")
    if not rc_raw:
        return (False, "no response_content")

    try:
        rc = parse_rc(rc_raw)
        return (True, rc)
    except Exception as e:
        return (False, f"response_content parse error: {e}")

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument(
        "--path",
        default=r"d:\DAIHOC_D\namtu\C\week6\*.log",
        help="Đường dẫn file hoặc glob (vd: d:\\DAIHOC_D\\namtu\\C\\week6\\2025-10-30.log hay ...\\*.log)"
    )
    args = ap.parse_args()

    paths = glob.glob(args.path)
    if not paths:
        print(f"❌ Không tìm thấy file nào khớp: {args.path}")
        return

    num_requests = 0
    num_bh_fail = 0
    num_bd_fail = 0

    total_lines = 0
    parsed_rc = 0
    skipped = 0
    reasons = {}

    for p in paths:
        pth = Path(p)
        try:
            with pth.open("r", encoding="utf-8", errors="ignore") as f:
                for line in f:
                    total_lines += 1
                    ok, val = parse_line(line)
                    if not ok:
                        skipped += 1
                        reasons[val] = reasons.get(val, 0) + 1
                        continue

                    rc = val
                    parsed_rc += 1
                    num_requests += 1

                    data = rc.get("data") or {}
                    msg = data.get("message")

                    counted_from_dict = False

                    # 1) Đếm từ data.message dạng dict { 'BHxxx': {'result': 0|1, ...}, ... }
                    if isinstance(msg, dict) and msg:
                        counted_from_dict = True
                        for code, res in msg.items():
                            try:
                                if isinstance(res, dict):
                                    if "result" in res:
                                        is_fail = int(res.get("result", 1)) == 0
                                    else:
                                        is_fail = (res.get("success") is False)
                                    if is_fail:
                                        code_str = str(code).upper()
                                        if code_str.startswith("BH"):
                                            num_bh_fail += 1
                                        elif code_str.startswith("BD"):
                                            num_bd_fail += 1
                            except Exception:
                                pass

                    # 2) Nếu không có dict ở trên, fallback đếm từ data.check_correct (chuỗi)
                    if not counted_from_dict:
                        check_correct = data.get("check_correct")
                        if isinstance(check_correct, str):
                            s = check_correct.upper()
                            if "BH0" in s:
                                num_bh_fail += 1
                            if "BD0" in s:
                                num_bd_fail += 1

        except Exception as e:
            print(f"⚠️ Không đọc được {p}: {e}")

    print("📊 Tổng kết:")
    print(f"  Số file đọc: {len(paths)}")
    print(f"  Tổng số dòng: {total_lines}")
    print(f"  Số dòng parse được response_content: {parsed_rc}")
    print(f"  Số dòng bị bỏ qua: {skipped}")
    if reasons:
        print("  Lý do skip (top):")
        for r, c in sorted(reasons.items(), key=lambda x: -x[1])[:5]:
            print(f"    - {r}: {c}")

    print(f"\n✅ Kết quả:")
    print(f"  Tổng số request: {num_requests}")
    print(f"  Tổng số BH fail: {num_bh_fail}")
    print(f"  Tổng số BD fail: {num_bd_fail}")

if __name__ == "__main__":
    main()