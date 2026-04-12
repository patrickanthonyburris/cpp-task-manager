#include "Task.hpp"

// Default Constructor
Task::Task() : completed(0), priority(0), due_date("TBD"), name("TBD") { std::cout << "Default Constructor for Task\n";}

// Constructor
Task::Task(int priority, std::string due_date, std::string name, int taskID) : completed(0), priority(priority), due_date(due_date), name(name), taskID(taskID) {}

// Helper
// Prints out all details of a task
void Task::print_details() const {
    if (!this->completed) {
    std::cout << "Task: " << this->name << std::endl;
    std::cout << "Due date: " << this->due_date<< std::endl;
    std::cout << "Priority Level: " << this->priority << std::endl;
    std::cout << "taskID: " << this->taskID << std::endl;
    } else {
    std::cout << "This task is already completed!" << std::endl;
    }
}

// API
// Prints task details
void Task::print_task() const {
	print_details();
}
