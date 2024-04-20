#include "header.h"
#include <iostream>
#include <random>
#include <vector>


//Methode random bot choice
char Bot::choiceBot(std::vector<char>& actionPlay) {

	// Check if the vector is empty
	if (!actionPlay.empty()) {
		// Random char in the vector
		int randomIndex = rand() % actionPlay.size();

		char action = actionPlay[randomIndex];

		// Delete the chosen char
		actionPlay.erase(actionPlay.begin() + randomIndex);
		return action;
	}

	
}





//---------------------------------------------Interface Method-----------------------------------------------------------

Game::Game(){
	// Interface initialized
	char initialInterface[5][15] = {
		{' ', '1', ' ', '|', ' ', '2', ' ', '|', ' ', '3', ' '},
		{'-', '-', '-', '|', '-', '-', '-', '|', '-', '-', '-'},
		{ ' ', '4', ' ', '|', ' ', '5', ' ', '|', ' ', '6', ' ' },
		{ '-', '-', '-', '|', '-', '-', '-', '|', '-', '-', '-' },
		{ ' ', '7', ' ', '|', ' ', '8', ' ', '|', ' ', '9', ' ' }};


		// copy info on the var interface
		for (int r = 0; r < 5; ++r) {
			for (int c = 0; c < 15; ++c) {
				interface[r][c] = initialInterface[r][c];
			}
		}
}


// methode to show the initial UI
void Game::showInterface() {
	for (int r = 0; r < row; r++) {
		for (int c = 0; c < column; c++) {
			std::cout << interface[r][c];
		}
		std::cout << "\n";
	}
}

void Game::crossAction(char choice) {
	for (int r = 0; r < row; r++) {
		for (int c = 0; c < column; c++) {
			// choice = number on the interface -> replace number by X
			if (choice == interface[r][c]) {
				std::cout << 'X';
				//uptdate the interface
				interface[r][c] = 'X';
			}//else show the interface
			else std::cout << interface[r][c];

		}
		std::cout << "\n";

	}
}

void Game::circleAction(char choice) {
	for (int r = 0; r < row; r++) {
		for (int c = 0; c < column; c++) {
			// choice = number on the interface -> replace number by O
			if (choice == interface[r][c]) {
				std::cout << 'O';
				//update the interface
				interface[r][c] = 'O';
			}
			//else show the interface
			else std::cout << interface[r][c];
		}
		std::cout << "\n";
	}
}


// ----------------------------------Victory Method----------------------------------
bool Game::verifyEachLine(int line) {
	int crossPresent = 0;
	int circlePresent = 0;

	for (int c = 0; c < column; c++) {
		if (cross == interface[line][c]) {
			crossPresent++;
		}
		else if (circle == interface[line][c]) {
			circlePresent++;
		}
	}
	if (crossPresent == 3) {
		std::cout << "\n(X) Win\n";
		return true;
	}
	else if (circlePresent == 3) {
		std::cout << "\n(O) Win\n";
		return true;
	}
	return false;
}

bool Game::verifyDiagonal() {

	if ((interface[0][1] == 'X' && interface[2][5] == 'X' && interface[4][9] == 'X') || (interface[0][9] == 'X' && interface[2][5] == 'X' && interface[4][1] == 'X')) {
		std::cout << "\n(X) win\n";
		return true;
	}

	else if ((interface[0][1] == 'O' && interface[2][5] == 'O' && interface[4][9] == 'O') || (interface[0][9] == 'O' && interface[2][5] == 'O' && interface[4][1] == 'O')) {
		std::cout << "\n(O) win\n";
		return true;
	}
	return false;


}

bool Game::verifyVertical() {
	// check if 3 columns have the same symbol
	for (int col = 0; col < 3; ++col) {
		//go to the i
		if (interface[0][col * 4 + 1] == 'X' && interface[2][col * 4 + 1] == 'X' && interface[4][col * 4 + 1] == 'X') {
			std::cout << "\n(X) win ! \n";
			return true;
		}
		else if (interface[0][col * 4 + 1] == 'O' && interface[2][col * 4 + 1] == 'O' && interface[4][col * 4 + 1] == 'O') {
			std::cout << "\n(O) win ! \n";
			return true;
		}
	}
	return false;

}

bool Game::verifyVictory(std::vector<char> actionPlay) {


	if (verifyDiagonal() == true || verifyEachLine(0) == true || verifyEachLine(2) == true || verifyEachLine(4) == true || verifyVertical() == true){
		return true;
	}

	else if (actionPlay.empty()) {
		std::cout << "\nEgality \n";
		return true;

	}
	
	return false;

}








