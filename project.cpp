#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool completed;

    Task(const std::string& desc) : description(desc), completed(false) {}
};

class TaskManager {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& description) {
        tasks.emplace_back(description);
        std::cout << "Task added: " << description << std::endl;
    }

    void markTaskComplete(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].completed = true;
            std::cout << "Task marked as completed: " << tasks[index].description << std::endl;
        } else {
            std::cout << "Invalid task index!" << std::endl;
        }
    }

    void displayTasks() {
        std::cout << "Tasks:" << std::endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". ";
            if (tasks[i].completed) {
                std::cout << "[X] ";
            } else {
                std::cout << "[ ] ";
            }
            std::cout << tasks[i].description << std::endl;
        }
    }
};

int main() {
    TaskManager manager;
    int choice;
    
    do {
        std::cout << "\nTask Manager Menu:\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. Mark Task as Completed\n";
        std::cout << "3. Display Tasks\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cin.ignore();
                std::string taskDescription;
                std::cout << "Enter task description: ";
                std::getline(std::cin, taskDescription);
                manager.addTask(taskDescription);
                break;
            }
            case 2: {
                int taskIndex;
                std::cout << "Enter task index to mark as completed: ";
                std::cin >> taskIndex;
                manager.markTaskComplete(taskIndex - 1);
                break;
            }
            case 3:
                manager.displayTasks();
                break;
            case 4:
                std::cout << "Exiting Task Manager. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 4);

    return 0;
}
