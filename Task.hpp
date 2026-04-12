#ifndef TASK_HPP
#define TASK_HPP
#include <iostream>
#include <string>

class Task {
    bool completed = 0;
    int priority = 0;
    std::string due_date;
    std::string name;
    int taskID = 0;

void print_details () const;
public:
Task();
Task(int priority, std::string due_date, std::string name, int taskID);
void print_task () const;
};
#endif
