# C++ Task Manager

A command-line task manager written in C++.

This project is a personal systems-style C++ practice project focused on:
- object-oriented design
- CLI argument parsing
- input validation
- basic task storage and management

## Features

Current functionality includes:
- Create tasks from the command line
- Store tasks in an `unordered_map`
- Validate integer input
- Validate due dates in `MM/DD/YYYY` format
- Print all current tasks

Planned functionality:
- List tasks more cleanly
- Delete tasks by ID
- Modify existing tasks
- Mark tasks as complete
- Persistent storage to a file

## Project Structure

```text
.
├── main.cpp
├── Task.hpp
├── Task.cpp
├── TaskManager.hpp
├── TaskManager.cpp
