#include <iostream>
#include <string>

using namespace std;

// Custom function to trim spaces
string removeSpaces(string str) {
    string result = "";
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] != ' ')
            result += str[i];
    }
    return result;
}

// Check if all characters are digits 
bool isAllDigits(const string& str) {
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}

// Implements Luhn's algorithm
bool validateWithLuhn(const string& number) {
    int total = 0;
    bool doubleIt = false;

    for (int i = number.length() - 1; i >= 0; --i) {
        int digit = number[i] - '0';

        if (doubleIt) {
            digit = digit * 2;
            if (digit > 9)
                digit = digit - 9;
        }

        total += digit;
        doubleIt = !doubleIt;
    }

    return (total % 10 == 0);
}

// Main interface loop
int main() {
    cout << "=======================================\n";
    cout << "||   Credit Card Validator (Luhn)    ||\n";
    cout << "=======================================\n";
    cout << "Enter 'quit' to exit.\n\n";

    while (true) {
        string input;
        cout << "Enter credit card number: ";
        getline(cin, input);

        if (input == "quit")
            break;

        string cleaned = removeSpaces(input);

        if (cleaned.empty()) {
            cout << "Input is empty. Try again.\n\n";
            continue;
        }

        if (!isAllDigits(cleaned)) {
            cout << "Invalid characters found. Use digits only.\n\n";
            continue;
        }

        if (validateWithLuhn(cleaned))
            cout << "✅ Valid credit card number!\n\n";
        else
            cout << "❌ Invalid credit card number.\n\n";
    }

    cout << "\nThank you for using the validator. Exiting...\n";
    return 0;
}
