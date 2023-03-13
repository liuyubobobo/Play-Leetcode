/// Source : https://leetcode.com/problems/minimum-time-to-complete-all-tasks/description/
/// Author : liuyubobobo
/// Time   : 2023-03-13

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;


/// Greedy
/// Time Complexity: O(nlogn + n * max_time)
/// Space Complexity: O(max_time)
class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {

        sort(tasks.begin(), tasks.end(), [](vector<int>& a, vector<int>& b) {
            if(a[1] != b[1]) return a[1] < b[1];
            return a[0] < b[0];
        });

        vector<int> used(2001, 0);
        for(const vector<int>& task: tasks){
            int start = task[0], end = task[1], duration = task[2];
            int cur = accumulate(used.begin() + start, used.begin() + (end + 1), 0);
            for(int i = end; i >= start && cur < duration; i --)
                if(!used[i]) used[i] = 1, cur ++;
        }

        return accumulate(used.begin(), used.end(), 0);
    }
};


int main() {

    return 0;
}
