#include "Task.hpp"

// Default Constructor
Task::Task() : completed(0), priority(0), due_date("TBD"), title("TBD") {}

// Constructor
Task::Task(int priority, std::string due_date, std::string title, int ID) : completed(0), priority(priority), due_date(due_date), title(title), ID(ID) {}

// Helper
// Prints out all details of the task
void Task::print_details() const {
    std::cout << "\nTask: " << this->title << "\n";
    std::cout << "Due date: " << this->due_date<< "\n";
    std::cout << "Priority Level: " << this->priority << "\n";
    std::cout << "TaskID: " << this->ID << "\n";
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
// Marks task as complete
void Task::mark_task_completed(int completion_status) {
	update_completed_variable(completion_status);
}

// Helper
// Sets title
void Task::set_title(std::string title) {
	this->title = title;
}

// API
// Changes the title to given title
void Task::change_title(std::string new_title) {
	set_title(new_title);
}

// Helper
// Sets priority level
void Task::set_priority(int priority) {
	this->priority = priority;
}

// API
// Changes the priority level to given priority
void Task::change_priority(int new_priority) {
	set_priority(new_priority);
}

// Helper
// Sets due date
void Task::set_due_date(std::string due_date) {
	this->due_date = due_date;
}

// API
// Changes the due date to provided due date
void Task::change_due_date(std::string due_date) {
	set_due_date(due_date);
}

// API
// Gets title
const std::string& Task::get_title() const {
	return this->title;
}

// API
// Gets ID
int Task::get_ID() const {
	return this->ID;
}

// API
// Gets priority
int Task::get_priority() const {
	return this->priority;
}

// API
// Gets due date
const std::string& Task::get_due_date() const {
	return this->due_date;
}

// API
// Gets completed
bool Task::get_completed() const {
	return this->completed;
}
