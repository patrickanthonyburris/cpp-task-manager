#include "taskManager.hpp"

void taskManager::add_task() {
	Tasks[this->current_task_ID] = Task();
	this->current_task_ID++;
}

void taskManager::create_task() {
	add_task();
}

void taskManager::remove_task(int taskID) {
	Tasks.erase(taskID);
}

void taskManager::print(int taskID) {
	Tasks[taskID].print_task();
}

void taskManager::print_task() {
	print(1);
}
