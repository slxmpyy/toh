// postfixstack.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Caden Johnson
// 9.26.2026
// Postfix Stack
//

#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string userExpression;
    stack<int> numbers;

    cout << "Enter your postfix expression ";
    cin >> userExpression;

    for (int i = 0; i < userExpression.length(); ++i) {
        if (isdigit(userExpression[i])) {                           //if current char is a number, push it on the stack
            numbers.push(userExpression[i] - '0');                  //converts the number char into an int
        }
        else {                                                      //must be an operator
            int val1 = numbers.top();
            numbers.pop();
            int val2 = numbers.top();
            numbers.pop();                                          //gets the two nums for the current operation

            switch (userExpression[i]) {                            //decides which operator to use depending on the current operator
            case '+':
                numbers.push(val2 + val1);
                break;                                              //breaks out of switch continues loop
            case '-':
                numbers.push(val2 - val1);
                break;
            case '*':
                numbers.push(val2 * val1);
                break;
            case '/':
                numbers.push(val2 / val1);
                break;
            }
        }
    }

    cout << userExpression << " is equal to " << numbers.top();     //all that remains in the stack is the answer


    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
