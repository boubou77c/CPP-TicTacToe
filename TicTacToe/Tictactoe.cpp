#include <iostream>
#include <random>
#include <vector>
#include "header.h"
#include <algorithm>
#include <time.h>
#include <thread>
typedef std::string string;

int main() {
	srand(time(NULL));

	std::vector<char> actionPlay = { '1','2','3','4','5','6','7','8','9' };

	Bot bot;
	Game game;
	char userChoice;

	std::cout << "\nWelcome to TicTacToe game, made by Boubou !\n\n-You start with O\n\n";

	game.showInterface();



	while (true) {
		//user input

		while (true) {
			std::cout << "\nUser  : ";
			std::cin >> userChoice;
			if (std::find(actionPlay.begin(), actionPlay.end(), userChoice) != actionPlay.end()) break;
			else std::cout << "\nYou have to enter a valid number !\n";
		}
		

		// Remove the userChoie in the vector
		auto it = std::remove(actionPlay.begin(), actionPlay.end(), userChoice);
		actionPlay.erase(it, actionPlay.end());

		std::cout << "\n";

		//update the interface
		game.circleAction(userChoice);

		//check victory
		if (game.verifyVictory(actionPlay) == true) {
			std::cout << "\nEnd Game\n";
			break;
		}

		//bot input 
		char botChoice = bot.choiceBot(actionPlay);
		std::cout <<"\nBot plays : " << botChoice << "\n";

		std::cout << "\n";
		//update the interface
		game.crossAction(botChoice);

		//check victory
		if (game.verifyVictory(actionPlay) == true) {
			std::cout << "\nEnd Game\n";
			break;
		}
		
	}

	std::this_thread::sleep_for(std::chrono::seconds(4));

	return 0;


}

































/*
int main() {
	char choice;

	char interface[5][15] = {
		{' ', '1', ' ', '|', ' ', '2', ' ', '|', ' ', '3', ' '},

		{'-', '-', '-', '|', '-', '-', '-', '|', '-', '-', '-'},

		{' ', '4', ' ', '|', ' ', '5', ' ', '|', ' ', '6', ' '},

		{'-','-','-','|','-','-','-','|','-','-','-'},

		{' ', '7', ' ', '|', ' ', '8', ' ', '|', ' ', '9', ' '} };

	int row = 5;
	int column = 15;



	std::vector<char> botAction;
	// Show the interface to play TIC TAC TOE
	for (int r = 0; r < row; r++) {
		for (int c = 0; c < column; c++) {
			std::cout << interface[r][c];
		}
		std::cout << "\n";
	}

	bool state =false;

	while (true) {

		std::cout << "\n\nWelcome to TicTacToe game, made by Boubou !\n-You start with O\n";

		// User input

		std::cout << "Where do you want to put the cross : \n\n";
		std::cin >> choice;

		//change the interface depending the choice
		for (int r = 0; r < row; r++) {
			for (int c = 0; c < column; c++) {
				if (choice == interface[r][c]) {
					std::cout << 'X';
					interface[r][c] = 'X';
				}
				else std::cout << interface[r][c];

			}
			std::cout << "\n";

		}
		std::cout << "\n";



		for (char c : botAction) {
			if (bot_choice == (c - '0')) {
				std::cout << "MHMH" << "\n";
				state = true;
				break;

			}
			std::cout << c << "\n";
			state = false;
		}

		std::cout << "\n";
		
		if (!state) {
			for (int r = 0; r < row; r++) {
				for (int c = 0; c < column; c++) {
					if (convertBotChoice == interface[r][c]) {
						std::cout << 'O';
						interface[r][c] = 'O';
						botAction.push_back(convertBotChoice);
					}
					else std::cout << interface[r][c];

				}
				std::cout << "\n";

			}
		}
		else {
			std::cout << "Bot is dumb \n";
		}

	}


	
}
*/



