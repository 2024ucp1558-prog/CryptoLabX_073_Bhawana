#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

string decryptText(const string& text, int key) {
    string result;

    for (char ch : text) {
        if (isupper(ch)) {
            result += char((ch - 'A' - key + 26) % 26 + 'A');
        }
        else if (islower(ch)) {
            result += char((ch - 'a' - key + 26) % 26 + 'a');
        }
        else {
            result += ch;
        }
    }

    return result;
}

unordered_set<string> loadDictionary(const string& filename) {
    unordered_set<string> dictionary;
    ifstream file(filename);

    string word;

    while (file >> word) {
        transform(word.begin(), word.end(), word.begin(),
                  [](unsigned char c) {
                      return tolower(c);
                  });

        dictionary.insert(word);
    }

    return dictionary;
}

int dictionaryScore(const string& text,
                    const unordered_set<string>& dictionary) {

    stringstream ss(text);
    string word;
    int score = 0;

    while (ss >> word) {

        string cleanWord;

        for (char ch : word) {
            if (isalpha(ch)) {
                cleanWord += tolower(ch);
            }
        }

        if (dictionary.count(cleanWord)) {
            score++;
        }
    }

    return score;
}

pair<int, string> dictionaryAttack(
    const string& ciphertext,
    const unordered_set<string>& dictionary) {

    int bestKey = 0;
    int bestScore = -1;
    string bestPlaintext;

    for (int key = 0; key < 26; key++) {

        string plaintext = decryptText(ciphertext, key);

        int score = dictionaryScore(plaintext, dictionary);

        if (score > bestScore) {
            bestScore = score;
            bestKey = key;
            bestPlaintext = plaintext;
        }
    }

    return {bestKey, bestPlaintext};
}
