#pragma once

#include<string>
using namespace std;

class RPG {
private:								//RPGs private attributes
	string playerName;
	int points;
	int wins;
	int teamHealth;

public:
	RPG(string playerName);				//RPGS public methods
	void addPoints();
	void addSomePoints();
	void addWin();
	void loseHealth(int amount);

	string getName();
	int getPoints();
	int getWins();
	int getTeamHealth();

	void display();
};