#ifndef TASKMANAGER_HPP
#define TASKMANAGER_HPP
#include <unordered_map>
#include "Task.hpp"

class TaskManager {
	std::unordered_map<int, Task> Tasks;
	int current_task_ID = 1;
	int num_tasks = 0;

void insert_task(int priority, std::string due_date, std::string name);
void remove_task(int taskID);
void mark_task_completed(int taskID);
void print_task_details(int taskID);
void print_all_task_details();
public:
void create_task(int priority, std::string due_date, std::string name);
int delete_task(int taskID);
void print_task(int taskID);
int complete_task(int taskID);
void print_all_tasks();
// Modify and access tasks functionality needed

};
#endif
