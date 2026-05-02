#ifndef TASK_HPP
#define TASK_HPP
#include <iostream>
#include <string>

class Task {
    bool completed = 0;
    int priority = 0;
    std::string due_date;
    std::string title;
    int ID = 0;

void print_details () const;
void update_completed_variable(int completion_status);
void set_title(std::string title);
void set_priority(int priority);
void set_due_date(std::string due_date);
public:
Task();
Task(int priority, std::string due_date, std::string title, int ID);
void print_task () const;
void mark_task_completed(int completion_status);
void change_title(std::string new_title);
void change_priority(int new_priority);
void change_due_date(std::string due_date);
const std::string& get_title() const;
int get_ID() const;
int get_priority() const;
const std::string& get_due_date() const;
bool get_completed() const;
};
#endif
