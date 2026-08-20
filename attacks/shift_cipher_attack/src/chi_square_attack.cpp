#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
#include <utility>

using namespace std;


string decryptText(const string& text, int key);

const double englishFrequency[26] = {
    8.167, 1.492, 2.782, 4.253, 12.702,
    2.228, 2.015, 6.094, 6.966, 0.153,
    0.772, 4.025, 2.406, 6.749, 7.507,
    1.929, 0.095, 5.987, 6.327, 9.056,
    2.758, 0.978, 2.360, 0.150, 1.974,
    0.074
};

double chiSquare(const string& text) {

    int observed[26] = {0};
    int totalLetters = 0;

    for (char ch : text) {

        if (isalpha(static_cast<unsigned char>(ch))) {

            char lower =
                static_cast<char>(
                    tolower(static_cast<unsigned char>(ch)));

            observed[lower - 'a']++;
            totalLetters++;
        }
    }

    if (totalLetters == 0) {
        return 1e9;
    }

    double score = 0.0;

    for (int i = 0; i < 26; i++) {

        double expected =
            englishFrequency[i] *
            totalLetters / 100.0;

        if (expected > 0) {

            double difference =
                observed[i] - expected;

            score +=
                (difference * difference) / expected;
        }
    }

    return score;
}

pair<int, string> chiSquareAttack(
    const string& ciphertext) {

    int bestKey = 0;
    double bestScore = 1e18;
    string bestPlaintext;

    for (int key = 0; key < 26; key++) {

        string plaintext =
            decryptText(ciphertext, key);

        double score =
            chiSquare(plaintext);

        if (score < bestScore) {

            bestScore = score;
            bestKey = key;
            bestPlaintext = plaintext;
        }
    }

    return {bestKey, bestPlaintext};
}
