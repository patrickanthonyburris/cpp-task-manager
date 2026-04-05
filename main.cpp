#include <iostream>
#include <limits>
#include "taskManager.hpp"

// Main menu prompt
void main_prompt() {
	std::cout << "Hello, welcome to TaskManager version 1.0!\n";
	std::cout << "What would you like to do?\n\t1. View all tasks\n\t2. Create a new task\n";
	std::cout << "\t3. Delete existing task\n\t4. Modify existing task\n";
}

// Check user input for validity
bool check_input(int user_input) {
	if(user_input < 0 || user_input > 4) {
		return 0;
	}
	return 1;
}

// Prompt user to choose menu option
int prompt_user_main_menu() {
	int user_input = 0;
	bool valid_input = 0;
	while(!valid_input) {
		main_prompt();
		std::cin >> user_input;
		if(std::cin.fail() || !check_input(user_input)) {
			std::cout << "Invalid input, please enter a 1, 2, 3, or 4.\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		valid_input = 1;
	}
	return user_input;
}

// Take user's input and call proper functions accordingly
void handle_menu_choice(int user_input, taskManager* Boss) {
	switch(user_input) {
		case 1:
		// Implement TaskManager to call proper task functions
		std::cout << "Option1\n";
		break;
		
		case 2:
		std::cout << "Option2\n";
		break;
		
		case 3:
		std::cout << "Option3\n";
		break;
		
		case 4:
		std::cout << "Option4\n";
		break;

		default:
		std::cout << "Unexpected error\n";

	}
}

int main() {
	taskManager Boss;

	int user_input = prompt_user_main_menu();
	handle_menu_choice(user_input, &Boss);
	return 0;
}
