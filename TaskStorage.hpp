#ifndef TASKSTORAGE_HPP
#define TASKSTORAGE_HPP
#include <iostream>
#include <fstream>
#include "Task.hpp"
#include "json.hpp"

class TaskStorage {
	std::string filename;

public:
	TaskStorage(std::string filename);
	bool save(const std::unordered_map<int, Task>& tasks, int next_id);	


};


#endif
