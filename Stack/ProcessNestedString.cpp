#include <string>
#include <stack>
#include <vector> // Not strictly needed for this version, but often useful
#include <cctype> // For isdigit

// It's good practice to put the function within a class or namespace,
// or ensure it's self-contained for simple cases like this.
// For this example, a standalone function is fine.

std::string functionA(std::string input) {
    std::stack<char> bracket;     // To keep track of opening brackets
    std::stack<std::string> stringst; // To store string segments before a '['
    std::stack<int> multiplier;   // To store numbers (multipliers)

    std::string current_decoded_string = ""; // This string gets built up
    int current_num = 0;

    for (int i = 0; i < input.length(); ++i) {
        char ch = input[i];

        if (isdigit(ch)) {
            // Build the full number
            current_num = current_num * 10 + (ch - '0');
        } else if (ch == '[') {
            // Push the multiplier and the string state before this bracket
            multiplier.push(current_num);
            stringst.push(current_decoded_string);
            bracket.push(ch); // Store the opening bracket

            // Reset for the content inside the new bracket
            current_decoded_string = "";
            current_num = 0; // Reset number for any potential new number inside
        } else if (ch == ']') {
            if (!bracket.empty() && bracket.top() == '[') {
                bracket.pop(); // Match the opening bracket
            } else {
                // Handle error: Unmatched ']' or invalid state
                // For simplicity, assuming valid input as per examples
            }

            if (!multiplier.empty() && !stringst.empty()) {
                int repeat_count = multiplier.top();
                multiplier.pop();

                std::string string_before_this_bracket = stringst.top();
                stringst.pop();

                std::string temp_repeated_part = "";
                for (int k = 0; k < repeat_count; ++k) {
                    temp_repeated_part += current_decoded_string;
                }
                current_decoded_string = string_before_this_bracket + temp_repeated_part;
            } else {
                // Handle error: ']' without corresponding '[' state or multiplier
                // For simplicity, assuming valid input
            }
        } else { // Character is a letter
            current_decoded_string += ch;
        }
    }

    // The final result is in current_decoded_string
    return current_decoded_string;
}

// Example usage (optional, for testing)
// #include <iostream>
// int main() {
//     std::cout << "Input: 3[abc]4[ab]c" << std::endl;
//     std::cout << "Output: " << functionA("3[abc]4[ab]c") << std::endl; // Expected: abcabcabcababababc

//     std::cout << "Input: 2[3[a]b]" << std::endl;
//     std::cout << "Output: " << functionA("2[3[a]b]") << std::endl;    // Expected: aaabaaab
    
//     std::cout << "Input: abc" << std::endl;
//     std::cout << "Output: " << functionA("abc") << std::endl;        // Expected: abc

//     std::cout << "Input: 3[a]2[bc]" << std::endl;
//     std::cout << "Output: " << functionA("3[a]2[bc]") << std::endl;  // Expected: aaabcbc

//     std::cout << "Input: 10[a]" << std::endl;
//     std::cout << "Output: " << functionA("10[a]") << std::endl;      // Expected: aaaaaaaaaa

//     std::cout << "Input: 2[a2[b]c]" << std::endl;
//     std::cout << "Output: " << functionA("2[a2[b]c]") << std::endl;  // Expected: abbcaabbc
//     return 0;
// }
