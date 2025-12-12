// Nhập vào 1 đoạn văn từ bán phím (tối đa 1000 chữ cái).
// Hãy in ra các tên riêng có trong đoạn văn theo thứ tự xuất hiện.
// Tên riêng là từ có ký tự đầu tiên được viết hoa, các từ được ngăn cách với nhau bởi 1 dấu cách trống hoặc dấu câu.
// Độ dài tên riêng từ 2 ký tự trở lên và bắt đầu phải bằng chữ cái.
// Tên riêng xuất hiện nhiều lần thì in nhiều lần.
// INPUT
// A rights group based in New York City says it has documents from Chinese officials that show a plan to push rural Tibetans into cities against their will.Human Rights Watch released a report recently that provides evidence against official Chinese statements that many Tibetans have moved voluntarily. The report said that, by the end of 2025, more than 930,000 rural Tibetans will have been moved to city areas. It said the Tibetans will not be able to get traditional jobs and will be limited in ways to make money.

// OUTPUT
// New York City Chinese Tibetans Human Rights Watch Chinese Tibetans The Tibetans It Tibetans
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string text, line;
    
    while (getline(cin, line)) {
        text += line + " "; 
    }

    for (int i = 0; i < text.length(); i++) {
        char c = text[i];
        if (isalnum(c) || c == '\'' || c == '-') {
            continue;
        } else {
            text[i] = ' ';
        }
    }

    stringstream ss(text);
    string word;
    bool first = true; 

    while (ss >> word) {
        if (word.length() >= 2 && isupper(word[0])) {
            if (!first) cout << " ";
            cout << word;
            first = false;
        }
    }
    
    return 0;
}