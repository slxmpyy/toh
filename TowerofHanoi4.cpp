// TowerofHanoi4.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 
// Caden Johnson
// 2026
// 
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void TowerDisks(const vector<char>& T1, const vector<char>& T2, const vector<char>& T3) {				//Outputs each tower number with which, if any, block they hold
	cout << "T1 ";
	for (char element : T1) {
		cout << element << " ";
	}

	cout << '\n' << "T2 ";
	for (char element : T2) {
		cout << element << " ";
	}

	cout << '\n' << "T3 ";
	for (char element : T3) {
		cout << element << " ";
	}

	cout << '\n';
}

int main()
{
	vector<char> T1{ 'A', 'B', 'C', 'D'};				//Tower 1 vector
	vector<char> T2;									//Tower 2 vector
	vector<char> T3;									//Tower 3 vector each hold the blocks
	int sourceT = 0;
	int destinationT = 0;
	char userBlock;
	bool crush = false;

	while (crush == false) {																				//Puzzle runs until the user crushes a block
		cout << "Please enter a source tower number and a destination tower number: " << '\n';
		cin >> sourceT;
		cin >> destinationT;

		if (sourceT == 1) {
			if (T1.empty()) {
				cout << "That source tower doesn't have a block to move!\nRETRY\n";
				continue;
			}
			userBlock = T1.back();
			T1.pop_back();
			if (destinationT == 2) {
				T2.push_back(userBlock);
				if (T2.size() >= 2 && T2.back() < T2[T2.size() - 2]) {												//Compares the block on top to the block right beneath it A < B < C < D
					cout << "You crushed a block!\n";																	//Also makes sure there is at least 2 blocks to compare otherwise error
					crush = true;
				}
			}
			else if (destinationT == 3) {
				T3.push_back(userBlock);
				if (T3.size() >= 2 && T3.back() < T3[T3.size() - 2]) {
					cout << "You crushed a block!\n";
					crush = true;
				}
			}
		}
		else if (sourceT == 2) {
			if (T2.empty()) {
				cout << "That source tower doesn't have a block to move!\nRETRY\n";
				continue;
			}
			userBlock = T2.back();
			T2.pop_back();
			if (destinationT == 1) {
				T1.push_back(userBlock);
				if (T1.size() >= 2 && T1.back() < T1[T1.size() - 2]) {
					cout << "You crushed a block!\n";
					crush = true;
				}
			}
			else if (destinationT == 3) {
				T3.push_back(userBlock);
				if (T3.size() >= 2 && T3.back() < T3[T3.size() - 2]) {
					cout << "You crushed a block!\n";
					crush = true;
				}
			}
		}
		else {
			if (T3.empty()) {
				cout << "That source tower doesn't have a block to move!\nRETRY\n";
				continue;
			}
			userBlock = T3.back();
			T3.pop_back();
			if (destinationT == 2) {
				T2.push_back(userBlock);
				if (T2.size() >= 2 && T2.back() < T2[T2.size() - 2]) {
					cout << "You crushed a block!\n";
					crush = true;
				}
			}
			else if (destinationT == 1) {
				T1.push_back(userBlock);
				if (T1.size() >= 2 && T1.back() < T1[T1.size() - 2]) {
					cout << "You crushed a block!\n";
					crush = true;
				}
			}

		}
		TowerDisks(T1, T2, T3);

		if (T3.size() == 4) {															//Only way T3 could have 4 elements is if they win
			cout << "You won!";
			break;
		}
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
