#include <iostream>
#include "RPG.h"
using namespace std;

RPG::RPG(string playerName) {						//RPGs constructor to start
	this->playerName = playerName;
	points = 0;
	wins = 0;
	teamHealth = 100;
}
void RPG::addPoints() {								//RPGs setters
	points += 120;
}
void RPG::addSomePoints() {
	points += 90;
}
void RPG::addWin() {
	wins++;
}
void RPG::loseHealth(int amount) {
	teamHealth -= amount;
}
string RPG::getName() {								//RPGs getters
	return playerName;
}
int RPG::getPoints() {
	return points;
}
int RPG::getWins() {
	return wins;
}
int RPG::getTeamHealth() {
	return teamHealth;
}
void RPG::display() {								//RPGs display
	cout << '\n' << playerName <<
		"\nTotal points: " << points <<
		"\nSeason wins: " << wins <<
		"\nTeam health: " << teamHealth;
}