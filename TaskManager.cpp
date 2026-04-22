#include "TaskManager.hpp"

// Helper
// Inserts a task into the Hash Map
void TaskManager::insert_task(int priority, std::string due_date, std::string name) {
	int taskID = this->current_task_ID;
	Tasks[this->current_task_ID] = Task(priority, due_date, name, taskID);
	this->current_task_ID++;
	this->num_tasks++;
}

// API
// Creates a new task using provided task details
void TaskManager::create_task(int priority, std::string due_date, std::string name) {
	insert_task(priority,due_date,name);
}

// Helper
// Removes task from Hash Map
void TaskManager::remove_task(int taskID) {
	Tasks.erase(taskID);
	this->num_tasks--;
}

// API
// Removes task from Hash Map
int TaskManager::delete_task(int taskID) {
	if(Tasks.find(taskID) == Tasks.end()) {
		return 0;
	}
	remove_task(taskID);
	return 1;
	
}

// Helper
// Prints all details of a single task, member variables
void TaskManager::print_task_details(int taskID) {
	Tasks[taskID].print_task();
}

// API
// Prints a task and its information
void TaskManager::print_task(int taskID) {
	print_task_details(taskID);
}

// Helper
// Prints all tasks and their respective details
void TaskManager::print_all_task_details() {
	for(const auto& [task_id, task] : Tasks) {
		task.print_task();
		std::cout << "\n";
	}
}

// API
// Prints all tasks
void TaskManager::print_all_tasks() {
	print_all_task_details();
}

// Helper
// Mark a specifc task to completed via taskID
void TaskManager::mark_task_completed(int taskID) {
	Tasks[taskID].mark_task_completed();
}

// API
// Update a task to completed
int TaskManager::complete_task(int taskID) {
	if(Tasks.find(taskID) == Tasks.end()) {
		return 0;
	}
	mark_task_completed(taskID);
		return 1;
}
