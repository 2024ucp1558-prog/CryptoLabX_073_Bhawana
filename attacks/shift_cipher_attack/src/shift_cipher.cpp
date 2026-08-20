#include <iostream>
#include <string>
#include <cctype>

using namespace std;

char shiftChar(char ch, int key) {
    if (isupper(ch)) {
        return char((ch - 'A' + key + 26) % 26 + 'A');
    }

    if (islower(ch)) {
        return char((ch - 'a' + key + 26) % 26 + 'a');
    }

    return ch;
}

string encryptText(const string& text, int key) {
    string result;

    for (char ch : text) {
        result += shiftChar(ch, key);
    }

    return result;
}

string decryptText(const string& text, int key) {
    return encryptText(text, -key);
}
