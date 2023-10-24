#include <iostream>
#include <string>

const int MAX_TASKS = 100;

struct Task {
    std::string description;
    bool completed;
};

class ToDoList {
private:
    Task tasks[MAX_TASKS];
    int taskCount;

public:
    ToDoList() : taskCount(0) {}

    void addTask(const std::string& description) {
        if (taskCount < MAX_TASKS) {
            tasks[taskCount].description = description;
            tasks[taskCount].completed = false;
            taskCount++;
            std::cout << "Task added successfully.\n";
        } else {
            std::cout << "Max task limit reached.\n";
        }
    }

    void viewTasks() {
        if (taskCount == 0) {
            std::cout << "No tasks in the list.\n";
            return;
        }

        std::cout << "To-Do List:\n";
        for (int i = 0; i < taskCount; ++i) {
            std::cout << (i + 1) << ". ";
            if (tasks[i].completed)
                std::cout << "[X] ";
            else
                std::cout << "[ ] ";
            std::cout << tasks[i].description << "\n";
        }
    }

    void markTaskAsCompleted(int taskIndex) {
        if (taskIndex >= 1 && taskIndex <= taskCount) {
            tasks[taskIndex - 1].completed = true;
            std::cout << "Task marked as completed.\n";
        } else {
            std::cout << "Invalid task index.\n";
        }
    }

    void removeTask(int taskIndex) {
        if (taskIndex >= 1 && taskIndex <= taskCount) {
            for (int i = taskIndex - 1; i < taskCount - 1; ++i) {
                tasks[i] = tasks[i + 1];
            }
            taskCount--;
            std::cout << "Task removed successfully.\n";
        } else {
            std::cout << "Invalid task index.\n";
        }
    }
};

int main() {
    ToDoList toDoList;

    while (true) {
        std::cout << "\nOptions:\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Remove Task\n";
        std::cout << "5. Quit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string description;
                std::cout << "Enter task description: ";
                std::cin.ignore();
                std::getline(std::cin, description);
                toDoList.addTask(description);
                break;
            }
            case 2:
                toDoList.viewTasks();
                break;
            case 3: {
                int taskIndex;
                std::cout << "Enter task index to mark as completed: ";
                std::cin >> taskIndex;
                toDoList.markTaskAsCompleted(taskIndex);
                break;
            }
            case 4: {
                int taskIndex;
                std::cout << "Enter task index to remove: ";
                std::cin >> taskIndex;
                toDoList.removeTask(taskIndex);
                break;
            }
            case 5:
                std::cout << "Goodbye!\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

