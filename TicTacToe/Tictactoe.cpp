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




