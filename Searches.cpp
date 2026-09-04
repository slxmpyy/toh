// Searches.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Whats in a name - Searches
// Linear and Binary search
// 
// Caden Johnson 
// 8.29.2026
//

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

int linearSearch(const vector<char>& VOWELS, char letter);
int binarySearch(const vector<char>& VOWELS, char letter);

int main()
{
    const vector<char> VOWELS{ 'a', 'e', 'i', 'o', 'u' };
    string userName;
    vector<char> vowelsInName;                                  //vowels found

    cout << "Please enter your name\n";
    getline(cin, userName);

    for (char letter : userName) {                              //iterating userName
        char trueLetter = tolower(letter);                      //make uppercase lower
        if (binarySearch(VOWELS, trueLetter) != -1) {           //if binarySearch doesnt return -1, then vowel
            cout << letter << " ";
            vowelsInName.push_back(letter);
        }
    }

    cout << "\nVector: ";
    for (char vowel : vowelsInName) {
        cout << vowel << " ";
    }

    return 0;
}

int linearSearch(const vector<char>& VOWELS, char letter)
{
    for (int i = 0; i < VOWELS.size(); i++) {                   //iterating VOWELS
        if (VOWELS[i] == letter) {
            return i;
        }
    }

    return -1;
}

int binarySearch(const vector<char>& VOWELS, char letter)
{
    int first = 0;
    int last = VOWELS.size() - 1;
    
    while (first <= last) {
        int middle = (first + last) / 2;
        if (VOWELS[middle] == letter) {
            return middle;
        }
        else if (letter > VOWELS[middle]) {
            first = middle + 1;
        }
        else {
            last = middle - 1;
        }
    }
    return -1;
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
