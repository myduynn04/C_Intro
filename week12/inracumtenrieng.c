// Cụm tên riêng là các tên riêng được viết liền nhau trong văn bản. Ví dụ cho câu sau

// India's Prime Minister Narendra Modi shows his ink-marked finger after casting his vote outside a polling station in Ahmedabad, India

// thì cụm tên riêng sẽ là 

// India's Prime Minister Narendra Modi
// Ahmedabad
// India

// Hãy viết chương trình nhập vào 1 đoạn văn (không quá 1000 từ)
// In ra các cục tên riêng trong đoạn văn đó theo thứ tự xuất hiện, mỗi cụm được in ra trên 1 dòng riêng
// INPUT
// It burns beautifully. It's a Russian S-300. On Russian territory. The first days after permission to use Western weapons on enemy territory.

// OUTPUT
// It's
// Russian S-300
// Russian
// The
// Western

#include <iostream>
#include <string>
#include <vector>
#include <cctype>   

using namespace std;

bool isPunctuation(char c) {
    return c == '.' || c == ',' || c == ';' || c == ':' || c == '!' || c == '?';
}

void printAndClear(vector<string> &buffer) {
    if (buffer.empty()) return;
    
    for (size_t i = 0; i < buffer.size(); i++) {
        cout << buffer[i] << (i == buffer.size() - 1 ? "" : " ");
    }
    cout << endl;
    buffer.clear();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string word;
    vector<string> current_phrase;

    while (cin >> word) {
        if (word.empty()) continue;

        char lastChar = word.back();
        bool hasBreaker = isPunctuation(lastChar);
        
        string cleanWord = word;
        if (hasBreaker) {
            cleanWord.pop_back(); 
        }

        if (cleanWord.empty()) {
            printAndClear(current_phrase);
            continue;
        }

        if (isupper(cleanWord[0])) {
            current_phrase.push_back(cleanWord);
            
            if (hasBreaker) {
                printAndClear(current_phrase);
            }
        } else {
            printAndClear(current_phrase);
        }
    }

    printAndClear(current_phrase);

    return 0;
}
