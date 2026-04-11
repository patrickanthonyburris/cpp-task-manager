#include "taskManager.hpp"

// Helper
// Inserts a task into the Hash Map
void taskManager::insert_task(int priority, std::string due_date, std::string name) {
	Tasks[this->current_task_ID] = Task(priority, due_date, name);
	this->current_task_ID++;
	this->num_tasks++;
}

// API
// Creates a new task using provided task details
void taskManager::create_task(int priority, std::string due_date, std::string name) {
	insert_task(priority,due_date,name);
}

// Helper
// Removes task from Hash Map
void taskManager::remove_task(int taskID) { // Needs more work
	Tasks.erase(taskID);
	this->num_tasks--;
}

// Helper
// Prints all details of a single task, member variables
void taskManager::print_task_details(int taskID) {
	Tasks[taskID].print_task();
}

// API
// Prints a task and its information
void taskManager::print_task(int taskID) {
	print_task_details(taskID);
}

// Helper
// Prints all tasks and their respective details
void taskManager::print_all_task_details() {
	for(const auto& [task_id, task] : Tasks) {
		task.print_task();
		std::cout << "\n";
	}
}

// API
// Prints all tasks
void taskManager::print_all_tasks() {
	print_all_task_details();
}
