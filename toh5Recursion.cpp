// Toh5Recursion.cpp : This file contains the 'main' function. Program execution begins and ends there. 
// Caden Johnson
// 9.29.2026
// Tower of Hanoi
//

#include <iostream>
#include <vector>

using namespace std;

void TowerDisks(const vector<char>& T1, const vector<char>& T2, const vector<char>& T3) {
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

void simulateTOH(int n, vector<char>& source, vector<char>& destination, vector<char>& helper) {
	if (n == 1) {																//base case when one is left on source tower
		char userBlock = source.back();
		source.pop_back();
		destination.push_back(userBlock);

		return;
	}

	simulateTOH(n - 1, source, helper, destination);							//moves n-1 blocks from source to helper

	char userBlock = source.back();												//moves biggest block to original destination tower
	source.pop_back();
	destination.push_back(userBlock);

	simulateTOH(n - 1, helper, destination, source);							//moves the n-1 blocks from helper to original destination tower
}

int main() {
	vector<char> T1{ 'A', 'B', 'C', 'D', 'E' };
	vector<char> T2;
	vector<char> T3;

	cout << "Starting Towers:\n";
	TowerDisks(T1, T2, T3);

	simulateTOH(5, T1, T3, T2);

	cout << "\nAfter solving 5 disks:\n";
	TowerDisks(T1, T2, T3);

	return 0;
}