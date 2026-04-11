#include "Task.hpp"

Task::Task() : completed(0), priority(0), due_date("TBD"), name("TBD") { std::cout << "Default Constructor for Task\n";}

Task::Task(int priority, std::string due_date, std::string name) : completed(0), priority(priority), due_date(due_date), name(name) {}

void Task::print() const {
    if (!this->completed) {
    std::cout << "Task: " << this->name << std::endl;
    std::cout << "Due date: " << this->due_date<< std::endl;
    std::cout << "Priority Level: " << this->priority << std::endl;
    } else {
    std::cout << "This task is already completed!" << std::endl;
    }
}

void Task::print_task() const {
    print();
}
