#pragma once
#ifndef ACTION_GAME
#define ACTION_GAME
#include <vector>
#include <iostream>


//Bot class

class Bot {
public:
	std::vector<char> actionPlay;
	char choiceBot(std::vector<char>& actionPlay);

};


// Interface class
class Game : public Bot{
public:
	char interface[5][15];
	int row = 5;
	int column = 15;

	char cross = 'X';
	char circle = 'O';


	Game();
	void showInterface();
	void crossAction(char choice);
	void circleAction(char choice);

	bool verifyVictory(std::vector<char> actionPlay);
	bool verifyEachLine(int line);
	bool verifyDiagonal();
	bool verifyVertical();
};


#endif
