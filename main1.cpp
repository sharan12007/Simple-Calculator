#include <iostream>

using namespace std;

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        throw invalid_argument("Division by zero is not allowed.");
    }
    return a / b;
}

int main() {
    char operation;
    double num1, num2;
    char continueCalc;

    cout << "Welcome to the Simple Calculator!" << endl;

    do {
        cout << "Enter first number: ";
        cin >> num1;

        cout << "Enter an operator (+, -, *, /): ";
        cin >> operation;

        cout << "Enter second number: ";
        cin >> num2;

        try {
            switch (operation) {
                case '+':
                    cout << num1 << " + " << num2 << " = " << add(num1, num2) << endl;
                    break;
                case '-':
                    cout << num1 << " - " << num2 << " = " << subtract(num1, num2) << endl;
                    break;
                case '*':
                    cout << num1 << " * " << num2 << " = " << multiply(num1, num2) << endl;
                    break;
                case '/':
                    cout << num1 << " / " << num2 << " = " << divide(num1, num2) << endl;
                    break;
                default:
                    cout << "Error: Invalid operator." << endl;
                    break;
            }
        } catch (const invalid_argument& e) {
            cout << "Error: " << e.what() << endl;
        }

        cout << "Do you want to perform another calculation? (y/n): ";
        cin >> continueCalc;

    } while (continueCalc == 'y' || continueCalc == 'Y');

    cout << "Thank you for using the calculator. Goodbye!" << endl;

    return 0;
}
