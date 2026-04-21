#include <iostream>
#include <limits>
#include <functional>
#include "TaskManager.hpp"

// List of all commands and how to use them
void print_help() {
	std::cout << "Usage:\ntaskmanager <command> [options]\n";
	std::cout << "Commands:\n";
	std::cout << " add\t\tAdd a new task\n";
	std::cout << " list\t\tList all tasks\n";
	std::cout << " delete\t\tDelete a task by ID\n";
	std::cout << " modify\t\tModify an existing task\n";
	std::cout << " complete\tMark a task as complete\n";
}

// Print help page for add command
void print_add_help() {
	std::cout << "Usage:\n taskmanager add <title> [options]\n";
	std::cout << "Description:\n";
	std::cout << " Adds a new task to the task manager\n";
	std::cout << "Arguments:\n";
	std::cout << " <title>\tThe name or description of a task\n";
	std::cout << "Options:\n";
	std::cout << " -p, --priority <1-4>\tSet task priority\n";
	std::cout << "\t\t1 = Urgent\n\t\t2 = High\n\t\t3 = Medium (default)\n\t\t4 = Low\n";
	std::cout << "\n -d, --due <MM/DD/YYYY>\t Set due date\n";
	std::cout << "\n -h, --help\tShow this help message\n";
	std::cout << "Examples:\n";
	std::cout << " taskmanager add Laundry\n";
	std::cout << " taskmanager add Project --priority 1\n";
	std::cout << " taskmanager add Dishes -p 3 -d 04/25/2026\n";
}

void print_delete_help() {
	std::cout << "Usage:\n taskmanager delete <TaskID>\n";
	std::cout << "Description:\n";
	std::cout << " Deletes an existing task from the task manager\n";
	std::cout << "Arguments:\n";
	std::cout << " <TaskID>\tThe unique ID of the task to be deleted\n";
	std::cout << "Options:\n";
	std::cout << " -h, --help\tShow this help message\n";
	std::cout << "Examples:\n";
	std::cout << " taskmanager delete 5\n";
}

// Parse input to confirm integer
bool parse_int(const std::string& input, int& result) {
	try {
		size_t pos;
		result = std::stoi(input, &pos);

		if(pos != input.length()) {
			return false;
		}
		return true;
	} catch (...) {
		return false;
	}
}

// Verify a given input is in range of expected
bool in_range(int value, int min, int max) {
	return value >= min && value <= max; 
}

// Validate an integer input given different respective parameters
bool validate_int_input(const std::string& input, int& value, int min, int max) {
	if(!parse_int(input, value)) {
		std::cerr << "Error: Input must be a valid integer\n";
		return false;
	}
	if(!in_range(value, min, max)) {
		std::cerr << "Error: Input must be between " << min << " and " << max << std::endl;
		return false;
	}
	return true;
}

// Validate the date is in the right format and within expected values
bool validate_date(const std::string& date) {
	if(date.length() != 10) {
		std::cout << "Error: invalid date format\n";
		return false;
	}
	if(date[2] != '/' || date[5] != '/') {
		std::cout << "Error: invalid date format\n";
		return false;
	}

	std::string month = date.substr(0,2);
	int month_int = 0;
	std::string day = date.substr(3,2);
	int day_int = 0;
	std::string year = date.substr(6,4);
	int year_int = 0;
	if(!validate_int_input(month, month_int, 1, 12)) {
		std::cout << "Error: month must be a valid integer from 1-12\n";
		return false;
	} 
	if(!validate_int_input(day, day_int, 1, 31)) {
		std::cout << "Error: day must be a valid integer from 1-31\n";
		return false;
	} 
	if(!validate_int_input(year, year_int, 2026, 9999)) {
		std::cout << "Error: year must be a valid integer from 2026-9999\n";
		return false;
	} 
	return true;
}

// Handles the add command
int handle_add(TaskManager* mngr, int argc, char* argv[]) {
	if(argc < 3) {
		print_add_help();
		return 1;
	}
	
	std::string name = argv[2];
	std::string due_date = "";
	int priority = 0;

	for(int i = 3; i < argc; i++) {
		std::string arg = argv[i];

		if(arg == "--priority" || arg == "-p") {
			if((i + 1) >= argc) {
				std::cout << "Error: missing value for --priority\n";
				return 1;
			}
			if(!validate_int_input(argv[i+1], priority, 1, 4)) {
				return 1;
			}
			i++;
		}

		if(arg == "--due" || arg == "-d") {
			if((i + 1) >= argc) {
				std::cout << "Error: missing value for --due\n";
				return 1;
			}
			if(!validate_date(argv[i+1])) {
				return 1;
			}
			due_date = argv[i+1];
		}
	}
	mngr->create_task(priority, due_date, name);
	return 0;
}

// Handles the delete command
int handle_delete(TaskManager* mngr, int argc, char* argv[]) {
	if(argc < 3) {
		print_delete_help();
	}

	// implement delete
}

int main(int argc, char* argv[]) {
	TaskManager mngr;
	
	if(argc < 2) {
		print_help();
		return 1;
	}
	std::string command = argv[1];
	
	if(command == "add") {
		handle_add(&mngr, argc, argv);
	}
	if(command == "list") {
		// Implement list
	}
	if(command == "delete") {
		handle_delete(&mngr, argc, argv);
	}

	mngr.print_all_tasks(); // For testing
	return 0;
}
