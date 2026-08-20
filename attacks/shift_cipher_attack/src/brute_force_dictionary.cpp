#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <cctype>

using namespace std;


string decryptText(const string& text, int key);

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

int dictionaryScore(
    const string& text,
    const unordered_set<string>& dictionary) {

    stringstream ss(text);
    string word;
    int score = 0;

    while (ss >> word) {

        string cleanWord;

        for (char ch : word) {
            if (isalpha(static_cast<unsigned char>(ch))) {
                cleanWord +=
                    static_cast<char>(tolower(
                        static_cast<unsigned char>(ch)));
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

        int score = dictionaryScore(
            plaintext,
            dictionary);

        if (score > bestScore) {
            bestScore = score;
            bestKey = key;
            bestPlaintext = plaintext;
        }
    }

    return {bestKey, bestPlaintext};
}
