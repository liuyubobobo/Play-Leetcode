/// Source : https://leetcode.com/problems/design-a-todo-list/description/
/// Author : liuyubobobo
/// Time   : 2023-03-24

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;


/// Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class TodoList {

private:
    class Task {
    public:
        string description;
        int dueDate;
        vector<string> tags;
        bool completed;

        Task(const string& description, int dueDate, const vector<string>& tags, bool completed)
            : description(description), dueDate(dueDate), tags(tags.begin(), tags.end()), completed(completed) {}
    };

    vector<list<int>> user_tasks;
    vector<Task> task_list;

public:
    TodoList() : user_tasks(101){}

    int addTask(int userId, const string& taskDescription, int dueDate, const vector<string>& tags) {
        task_list.push_back(Task(taskDescription, dueDate, tags, false));

        int task_id = task_list.size();
        user_tasks[userId].push_back(task_id - 1);
        return task_id;
    }

    vector<string> getAllTasks(int userId) {
        vector<pair<string, int>> result;
        for (int task_id : user_tasks[userId])
            if(!task_list[task_id].completed)
                result.push_back({task_list[task_id].description, task_list[task_id].dueDate});
        return get_tasks_sorted_by_due_date(result);
    }

    vector<string> getTasksForTag(int userId, string tag) {
        vector<pair<string, int>> result;
        for (int task_id : user_tasks[userId]) {
            if (find(task_list[task_id].tags.begin(), task_list[task_id].tags.end(), tag) != task_list[task_id].tags.end() && !task_list[task_id].completed)
                result.push_back({task_list[task_id].description, task_list[task_id].dueDate});
        }
        return get_tasks_sorted_by_due_date(result);
    }

    void completeTask(int userId, int taskId) {
        if(find(user_tasks[userId].begin(), user_tasks[userId].end(), taskId - 1) != user_tasks[userId].end())
            task_list[taskId - 1].completed = true;
    }

private:
    vector<string> get_tasks_sorted_by_due_date(vector<pair<string, int>>& v) {
        sort(v.begin(), v.end(), [](pair<string, int> a, pair<string, int> b) {
            return a.second < b.second;
        });

        vector<string> ret;
        for(auto task : v)
            ret.push_back(task.first);
        return ret;
    }
};


int main() {

    TodoList todoList;
    cout << todoList.addTask(1, "Task1", 50, {}) << '\n'; // 1
    cout << todoList.addTask(1, "Task2", 100, {"P1"}) << '\n'; // 2

    vector<string> res = todoList.getAllTasks(1);
    for(const string& e: res) cout << e << ' '; cout << '\n'; // Task1, Task2

    res = todoList.getAllTasks(5);
    for(const string& e: res) cout << e << ' '; cout << '\n'; // empty

    cout << todoList.addTask(1, "Task3", 30, {"P1"}) << '\n'; // 3

    res = todoList.getTasksForTag(1, "P1");
    for(const string& e: res) cout << e << ' '; cout << '\n'; // Task3, Task2

    return 0;
}
