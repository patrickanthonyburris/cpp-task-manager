#include "Task.hpp"

// Default Constructor
Task::Task() : completed(0), priority(0), due_date("TBD"), name("TBD") {}

// Constructor
Task::Task(int priority, std::string due_date, std::string name, int taskID) : completed(0), priority(priority), due_date(due_date), name(name), taskID(taskID) {}

// Helper
// Prints out all details of a task
void Task::print_details() const {
    std::cout << "\nTask: " << this->name << "\n";
    std::cout << "Due date: " << this->due_date<< "\n";
    std::cout << "Priority Level: " << this->priority << "\n";
    std::cout << "TaskID: " << this->taskID << "\n";
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
void Task::update_completed_variable(int completion_status) {
	this->completed = completion_status;
}

// API
// Marks a task as complete
void Task::mark_task_completed(int completion_status) {
	update_completed_variable(completion_status);
}

// Helper
// Set title to given title
void Task::set_title(std::string title) {
	this->name = title;
}

// API
// Changes the title of a task 
void Task::change_title(std::string new_title) {
	set_title(new_title);
}
