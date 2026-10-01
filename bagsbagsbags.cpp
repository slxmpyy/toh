// bagsbagsbags.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Bags & Using
// Caden Johnson
// 9.18.2026
// Using is a keyword that creates an alias for a data type
// Good for readability and consistency
// 
//

#include <iostream>
using namespace std;

class Bags {
public:
    using value_type = int;                                             //value_type becomes int alias
    using size_type = std::size_t;                                      //size_t is the unsigned integer type of the result of operators sizeof or alignof
                                                                        //size_t is C++ standard type for representing how big something is or where something is located in a collection
                                                                        //size_type becomes size_t alias
    static const size_type capacity = 5;                                //static means this value belongs to the class itself, wont make a copy for each object

    value_type values[capacity];

    void insert() {
        cout << "Enter " << capacity << " values\n";
        for (size_type i = 0; i < capacity; ++i) {
            cin >> values[i];
        }
    }
};                                                                      
int main()
{
    Bags yslCheetah;

    yslCheetah.insert();

    cout << "\nCapacity: " << yslCheetah.capacity;
    cout << "\nValues: ";
    for (Bags::size_type i = 0; i < yslCheetah.capacity; ++i) {         //size_type cannot represent negative values because unsigned so used to iterate
        cout << yslCheetah.values[i] << ' ';
    }

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
