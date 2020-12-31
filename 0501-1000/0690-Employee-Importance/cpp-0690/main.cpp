/// Source : https://leetcode.com/problems/employee-importance/description/
/// Author : liuyubobobo
/// Time   : 2017-11-27

#include <iostream>
#include <vector>
#include <map>

using namespace std;


// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;

    Employee(int id, int importance, vector<int> subordinates):
            id(id), importance(importance), subordinates(subordinates){

    }
};

/// DFS
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

private:
    map<int, Employee*> record;

public:
    int getImportance(vector<Employee*> employees, int id) {

        record.clear();
        for(Employee* employee: employees)
            record[employee->id] = employee;
        return dfs(id);
    }

private:
    int dfs(int id){
        int res = record[id]->importance;
        for(int sid: record[id]->subordinates)
            res += dfs(sid);
        return res;
    }
};


int main() {

    vector<Employee*> vec = {
            new Employee(1, 5, {2, 3}),
            new Employee(2, 3, vector<int>()),
            new Employee(3, 3, vector<int>())
    };
    cout << Solution().getImportance(vec, 1) << endl;

    return 0;
}