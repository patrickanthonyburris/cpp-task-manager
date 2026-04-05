#ifndef TASKMANAGER_HPP
#define TASKMANAGER_HPP
#include <unordered_map>
#include "Task.hpp"

class taskManager {
	std::unordered_map<int, Task> Tasks;
	int current_task_ID = 1;

void add_task();
void remove_task(int);
void print(int taskID);
public:
void create_task();
void delete_task();
void print_task();
// Modify and access tasks functionality needed

};
#endif
