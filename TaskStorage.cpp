#include "TaskStorage.hpp"

// Constructor
TaskStorage::TaskStorage(std::string filename) : filename(filename) {}

bool TaskStorage::save(const std::unordered_map<int, Task>& tasks, int next_id) {
	nlohmann::json j;
	j["next_id"] = next_id;
	j["tasks"] = nlohmann::json::array();

	for(const auto& [id, task] : tasks) {
		nlohmann::json t;
		t["id"] = task.get_ID();
		t["title"] = task.get_title();
		t["priority"] = task.get_priority();
		t["due"] = task.get_due_date();
		t["completed"] = task.get_completed();

		j["tasks"].push_back(t);
	}

	std::ofstream file(filename);
	if(!file) {
		return false;
	}

	file << j.dump(4);
	return true;
}
