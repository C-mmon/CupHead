#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <cctype>

// Converts word to its digit string (like a phone number)
std::string wordToDigits(const std::string &word, const char letterToDigit[26]) {
    std::string digits;
    for (char ch : word) {
        if (ch < 'a' || ch > 'z') return ""; // invalid char
        digits += letterToDigit[ch - 'a'];
    }
    return digits;
}

std::vector<std::string> findMatchingWords(const std::string &phoneNumber, const std::set<std::string> &words) {
    std::vector<std::string> result;

    // Map: a-c -> 2, d-f -> 3, ..., w-z -> 9
    const char letterToDigit[26] = {
        '2','2','2',  // a b c
        '3','3','3',  // d e f
        '4','4','4',  // g h i
        '5','5','5',  // j k l
        '6','6','6',  // m n o
        '7','7','7','7',  // p q r s
        '8','8','8',  // t u v
        '9','9','9','9'   // w x y z
    };

    for (const auto &word : words) {
        if (word.length() != phoneNumber.length()) continue;

        std::string lowerWord;
        for (char c : word)
            lowerWord += std::tolower(c);

        std::string mapped = wordToDigits(lowerWord, letterToDigit);
        if (mapped == phoneNumber) {
            result.push_back(word); // original casing
        }
    }

    return result;
}

// Test case
int main() {
    std::set<std::string> dictionary = {"tree", "used", "apple", "bat", "cat"};
    std::string number = "8733";

    std::vector<std::string> matches = findMatchingWords(number, dictionary);

    std::cout << "Matching words for phone number " << number << ":\n";
    for (const auto& word : matches) {
        std::cout << word << "\n";
    }

    return 0;
}
