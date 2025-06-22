#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

// Function to add a task
void addTask(vector<Task>& tasks) {
    string desc;
    cout << "Enter task description: ";
    cin.ignore();
    getline(cin, desc);
    tasks.push_back({desc, false});
    cout << "Task added!\n";
}

// Function to view tasks
void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to display.\n";
        return;
    }

    cout << "\nTo-Do List:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". [" << (tasks[i].completed ? "✔" : " ") << "] "
             << tasks[i].description << "\n";
    }
    cout << "\n";
}

// Function to mark task as completed
void markCompleted(vector<Task>& tasks) {
    int index;
    cout << "Enter task number to mark as completed: ";
    cin >> index;
    if (index < 1 || index > (int)tasks.size()) {
        cout << "Invalid task number.\n";
        return;
    }
    tasks[index - 1].completed = true;
    cout << "Task marked as completed!\n";
}

// Function to remove a task
void removeTask(vector<Task>& tasks) {
    int index;
    cout << "Enter task number to remove: ";
    cin >> index;
    if (index < 1 || index > (int)tasks.size()) {
        cout << "Invalid task number.\n";
        return;
    }
    tasks.erase(tasks.begin() + index - 1);
    cout << "Task removed!\n";
}

// Main menu
void menu() {
    vector<Task> tasks;
    int choice;

    while (true) {
        cout << "\n=== To-Do List Menu ===\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addTask(tasks); break;
            case 2: viewTasks(tasks); break;
            case 3: markCompleted(tasks); break;
            case 4: removeTask(tasks); break;
            case 5: cout << "Goodbye!\n"; return;
            default: cout << "Invalid choice. Try again.\n";
        }
    }
}

int main() {
    menu();
    return 0;
}
