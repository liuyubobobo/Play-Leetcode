/// Source : https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/
/// Author : liuyubobobo
/// Time   : 2020-12-26

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(n^3)
/// Space Complexity: O(1)
class Solution {

public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {

        while(!students.empty()){
            if(students[0] != sandwiches[0]){
                if(all_same(students))
                    return students.size();
                int a = students[0];
                students.erase(students.begin());
                students.push_back(a);
            }
            else{
                students.erase(students.begin());
                sandwiches.erase(sandwiches.begin());
            }
        }
        return 0;
    }

private:
    bool all_same(const vector<int>& v){
        for(int i = 1; i < v.size(); i ++)
            if(v[0] != v[i]) return false;
        return true;
    }
};


int main() {

    return 0;
}
