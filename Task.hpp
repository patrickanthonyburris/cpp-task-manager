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
void update_completed_variable(int completion_status);
void set_title(std::string title);
public:
Task();
Task(int priority, std::string due_date, std::string name, int taskID);
void print_task () const;
void mark_task_completed(int completion_status);
void change_title(std::string new_title);
};
#endif
