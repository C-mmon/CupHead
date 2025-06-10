#include <iostream>
#include <string>
#include <cmath>
#include <cctype>

using namespace std;

double evaluation(string input, int &index) // Pass index by reference
{
    // Skip whitespace
    while (index < input.length() && input[index] == ' ')
    {
        index++;
    }

    // If it's a digit, parse the number
    if (isdigit(input[index]))
    {
        int startIndex = index;
        while (index < input.length() && isdigit(input[index]))
        {
            index++;
        }
        // Substring is string starting from index with length
        return stoi(input.substr(startIndex, index - startIndex));
    }

    // Parse the operator
    char op = '\0';
    if (isalpha(input[index]))
    {
        op = input[index];
        index += 4; // Skip the function name (e.g., 'add', 'mul', etc.)
    }

    // Skip the whitespace or opening parenthesis
    while (index < input.length() && (input[index] == ' ' || input[index] == '('))
    {
        index++;
    }

    // Recursively evaluate the first operand
    double operand1 = evaluation(input, index);

    // Skip whitespace or commas
    while (index < input.length() && (input[index] == ' ' || input[index] == ','))
    {
        index++;
    }

    // Recursively evaluate the second operand
    double operand2 = evaluation(input, index);

    // Skip closing parenthesis
    while (index < input.length() && (input[index] == ' ' || input[index] == ')'))
    {
        index++;
    }

    // Perform the operation
    switch (op)
    {
    case 'a': // add
        return operand1 + operand2;
    case 'p': // pow
        return pow(operand1, operand2);
    case 's': // subtract
        return operand1 - operand2;
    case 'd': // divide
        if (operand2 == 0)
        {
            cout << "Error: Division by zero" << endl;
            return 0; // Handle division by zero
        }
        return operand1 / operand2;
    case 'm': // multiply
        return operand1 * operand2;
    default:
        cout << "Invalid operator" << endl;
        return 0;
    }
}

int main()
{
    string expression = "add(pow(1,2),mul(2,3))";
    int index = 0; // Start parsing from the beginning
    double result = evaluation(expression, index);
    cout << "Result: " << result << endl; // Output the result
    return 0; // Indicate successful program termination
}