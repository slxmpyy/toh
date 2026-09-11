// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Lab 2 Fantasy Football RPG
// Classes
// Caden Johnson
// 9.10.2026
// CIS230
//

#include <iostream>
#include <string>
#include <vector>
#include "RPG.h"
using namespace std;

void week1(vector<RPG>& players);
void week2(vector<RPG>& players);
void week3(vector<RPG>& players);
void week4(vector<RPG>& players);
void week5(vector<RPG>& players);
void removeEliminated(vector<RPG>& players);
int main()
{
	vector<RPG> players;
	string name;

	cout << "Who will be participating in this season's fantasy league?\n";
	for (int i = 0; i < 3; i++) {
		cin >> name;
		players.push_back(RPG(name));
	}

	week1(players);																			//run each week to simulate fantasy weeks
	week2(players);
	removeEliminated(players);
	week3(players);
	removeEliminated(players);
	week4(players);
	removeEliminated(players);
	week5(players);
	removeEliminated(players);

	if (players.empty()) {
		cout << "\nEveryone has been eliminated!\n";
	}
	else {
		int greatest = 0;

		for (int i = 0; i < players.size(); i++) {
			if (players[i].getWins() > players[greatest].getWins()) {							//determine winner by most wins
				greatest = i;
			}
		}
		cout << "\nThis season's champion is " << players[greatest].getName() << '!';

	}

	return 0;
}
void week1(vector<RPG>& players) {
	for (int i = 0; i < players.size(); i++) {
		char choice;

		cout << "\n\nWEEK 1:\n" << 
			players[i].getName() << ", your RB1 is questionable at gametime.\n" <<
			"Will you (a) start him		(b) bench him for RB3\n";

		cin >> choice;
		if (choice == 'a') {
			players[i].addPoints();
			players[i].loseHealth(43);
			players[i].addWin();
		}
		else if (choice == 'b') {
			players[i].addSomePoints();
		}

		players[i].display();
	}
}
void week2(vector<RPG>& players) {
	for (int i = 0; i < players.size(); i++) {
		char choice;

		cout << "\n\nWEEK 2:\n" <<
			players[i].getName() << ", your WR2 sprained his ankle in practice before the coming game.\n" <<
			"Will you pick up (a) the steady-floor WR2		(b) the high-upside WR2\n";

		cin >> choice;
		if (choice == 'a') {
			players[i].addSomePoints();
			players[i].loseHealth(10);
		}
		else if (choice == 'b') {
			players[i].addPoints();
			players[i].addWin();
			players[i].loseHealth(10);
		}

		players[i].display();
	}
}
void week3(vector<RPG>& players) {
	for (int i = 0; i < players.size(); i++) {
		char choice;

		cout << "\n\nWEEK 3:\n" <<
			players[i].getName() << ", your WR1 has a rough matchup, shadowed by PS2.\n" <<
			"Will you (a) start him		(b) bench him for WR4\n";

		cin >> choice;
		if (choice == 'a') {
			players[i].addPoints();
			players[i].addWin();
		}
		else if (choice == 'b') {
			players[i].addSomePoints();
		}

		players[i].display();
	}
}
void week4(vector<RPG>& players) {
	for (int i = 0; i < players.size(); i++) {
		char choice;

		cout << "\n\nWEEK 4:\n" <<
			players[i].getName() << ", it's your RB2's bye week.\n" <<
			"Will you start (a) the injury prone but high-upside RB3		(b) the RB3 that splits a 50/50 workload\n";

		cin >> choice;
		if (choice == 'a') {
			players[i].addPoints();
			players[i].addWin();
			players[i].loseHealth(55);
		}
		else if (choice == 'b') {
			players[i].addSomePoints();
		}

		players[i].display();
	}

}
void week5(vector<RPG>& players) {
	for (int i = 0; i < players.size(); i++) {
		char choice;

		cout << "\n\nLAST WEEK:\n" <<
			players[i].getName() << ", your WR1 has a favorable matchup, but is playing at Metlife stadium.\n" <<
			"Will you (a) start him and pray he doesn't tear an acl		(b) bench him for a low-ceiling WR3\n";

		cin >> choice;
		if (choice == 'a') {
			players[i].addSomePoints();
			players[i].loseHealth(57);
		}
		else if (choice == 'b') {
			players[i].addSomePoints();
		}

		players[i].display();
	}
}
void removeEliminated(vector<RPG>& players) {
	for (int i = players.size() - 1; i >= 0; i--) {
		if (players[i].getTeamHealth() <= 0) {
			cout << '\n' << players[i].getName() << " has been eliminated!\n";
			players.erase(players.begin() + i);
		}
	}
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
