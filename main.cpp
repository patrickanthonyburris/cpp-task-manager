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
	if(user_input <= 0 || user_input > 4) {
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
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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

// Prompt user to create new task
void prompt_new_task(taskManager* Boss) {
	int priority = 0;
	std::string due_date;
	std::string name;

	std::cout << "What would you like your new task's name to be?\n";
	std::getline(std::cin, name);
	std::cout << "Please set a due date for this task (mm/dd/yyyy).\n";
	std::getline(std::cin, due_date);

	bool valid_input = 0;
	while(!valid_input) {
		std::cout << "What priority level is this task?\n1. Urgent\n2. High\n3. Medium\n4. Low\n";
		std::cin >> priority;
		if(std::cin.fail() || !check_input(priority)) {
			std::cout << "Invalid input, please enter a 1, 2, 3, or 4.\n";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		valid_input = 1;
	}
	Boss->create_task(priority, due_date, name);
}

// Prompt user to delete a task
void prompt_delete_task(taskManager* Boss) {
	int taskID = 0;
	int pass = 0;
	
	while(!pass) {
	bool valid_input = 0;
	while(!valid_input) {
	std::cout << "What is the taskID of the task you would like to delete? \n";
	std::cin >> taskID;
	if(std::cin.fail()) {
	std::cout << "Invalid input, please enter an integer.\n";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	continue;
	}
	valid_input = 1;
	}
	pass = Boss->delete_task(taskID);
	}
}

// Take user's input and call proper functions accordingly
void handle_menu_choice(int user_input, taskManager* Boss) {
	switch(user_input) {
		case 1:
			// Implement TaskManager to call proper task functions
			Boss->print_all_tasks();
			break;

		case 2:
			prompt_new_task(Boss);
			break;

		case 3:
			prompt_delete_task(Boss);
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

	bool end = 0;
	while(!end) {
		int user_input = prompt_user_main_menu();
		handle_menu_choice(user_input, &Boss);
		std::cout << "Do you want to exit?\n1) Yes\n0) No\n";
		std::cin >> end;
	}
	return 0;
}
