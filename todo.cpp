#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool completed;

    Task(const std::string& desc) : description(desc), completed(false) {}
};

void display_menu() {
    std::cout << "\nTo-Do List Manager\n";
    std::cout << "1. Add a task\n";
    std::cout << "2. View tasks\n";
    std::cout << "3. Mark task as completed\n";
    std::cout << "4. Delete a task\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice: ";
}

void add_task(std::vector<Task>& tasks) {
    std::string task_description;
    std::cout << "Enter the task description: ";
    std::cin.ignore(); // Clear the input buffer
    std::getline(std::cin, task_description);
    tasks.emplace_back(task_description);
    std::cout << "Task added successfully!\n";
}

void view_tasks(const std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks available.\n";
        return;
    }
    std::cout << "Your tasks:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". " << tasks[i].description
                  << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]\n";
    }
}

void mark_task_completed(std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks available to mark as completed.\n";
        return;
    }
    int task_index;
    std::cout << "Enter the task number to mark as completed: ";
    std::cin >> task_index;
    if (task_index > 0 && task_index <= tasks.size()) {
        tasks[task_index - 1].completed = true;
        std::cout << "Task marked as completed successfully!\n";
    } else {
        std::cout << "Invalid task number.\n";
    }
}

void delete_task(std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks available to delete.\n";
        return;
    }
    int task_index;
    std::cout << "Enter the task number to delete: ";
    std::cin >> task_index;
    if (task_index > 0 && task_index <= tasks.size()) {
        tasks.erase(tasks.begin() + task_index - 1);
        std::cout << "Task deleted successfully!\n";
    } else {
        std::cout << "Invalid task number.\n";
    }
}

int main() {
    std::vector<Task> tasks;
    int choice;

    while (true) {
        display_menu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                add_task(tasks);
                break;
            case 2:
                view_tasks(tasks);
                break;
            case 3:
                mark_task_completed(tasks);
                break;
            case 4:
                delete_task(tasks);
                break;
            case 5:
                std::cout << "Exiting...\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}
