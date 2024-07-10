#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Task {
    string title;
    string category;
    int progress; // Progress in percentage
};

// Progress tracking system class
class ProgressTracker {
private:
    vector<Task> tasks; 

public:
    // Function to add a new task
    void addTask(string title, string category) {
        Task newTask = {title, category, 0}; // Initialize progress to 0%
        tasks.push_back(newTask);
        cout << "Task '" << title << "' added to category '" << category << "'.\n";
    }

    // Function to update progress of a task
    void updateProgress(string title, int newProgress) {
        
        for (auto& task : tasks) {
            if (task.title == title) {
                task.progress = newProgress;
                cout << "Progress of task '" << title << "' updated to " << newProgress << "%.\n";
                return;
            }
        }
        cout << "Task '" << title << "' not found.\n";
    }

    // Function to display all tasks and their progress
    void displayTasks() {
        cout << "===== Tasks in Progress =====\n";
        cout << setfill(' ') << setw(20) << "Title" << setfill(' ') << setw(20) << "Category" << setfill(' ') << setw(20) << "Progress (%) \n";
        cout << "-----------------------------\n";
        for (auto& task : tasks) {
            cout << setfill(' ') << setw(20) << task.title << setfill(' ') << setw(20) << task.category << setfill(' ') << setw(20) << task.progress << endl;
        }
        cout << "-----------------------------\n";
    }
};

int main() {
    ProgressTracker tracker;
    int choice;
    string title, category;
    int progress;

    do {
        // Display menu
        cout << "\nProgress Tracking System Menu:\n";
        cout << "1. Add Task\n";
        cout << "2. Update Progress\n";
        cout << "3. Display Tasks\n";
        cout << "4. Exit\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter task title: ";
                cin.ignore(); // Ignore newline character left in the buffer
                getline(cin, title);
                cout << "Enter task category: ";
                getline(cin, category);
                tracker.addTask(title, category);
                break;
            case 2:
                cout << "Enter task title to update progress: ";
                cin.ignore(); // Ignore newline character left in the buffer
                getline(cin, title);
                cout << "Enter new progress percentage: ";
                cin >> progress;
                tracker.updateProgress(title, progress);
                break;
            case 3:
                tracker.displayTasks();
                break;
            case 4:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 4.\n";
				break;
        }

    } while (choice != 4);

    return 0;
}