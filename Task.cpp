#include "Task.hpp"

// Default Constructor
Task::Task() : completed(0), priority(0), due_date("TBD"), name("TBD") {}

// Constructor
Task::Task(int priority, std::string due_date, std::string name, int taskID) : completed(0), priority(priority), due_date(due_date), name(name), taskID(taskID) {}

// Helper
// Prints out all details of a task
void Task::print_details() const {
    std::cout << "Task: " << this->name << std::endl;
    std::cout << "Due date: " << this->due_date<< std::endl;
    std::cout << "Priority Level: " << this->priority << std::endl;
    std::cout << "TaskID: " << this->taskID << std::endl;
    std::cout << "Completion Status: ";
    if(!this->completed) {
	std::cout << "Incomplete\n";
	} else {
	std::cout << "Completed\n";
	}
}

// API
// Prints task details
void Task::print_task() const {
	print_details();
}

// Helper
// Updates internal completed boolean
void Task::update_completed_variable() {
	this->completed = 1;
}

// API
// Marks a task as complete
void Task::mark_task_completed() {
	update_completed_variable();
}
