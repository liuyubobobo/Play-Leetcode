/// Source : https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/
/// Author : liuyubobobo
/// Time   : 2022-09-12

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


/// Greedy and Using PQ
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());

        priority_queue<int, vector<int>, greater<int>> ends;
        for(const vector<int>& interval: intervals){
            int a = interval[0], b = interval[1];
            if(!ends.empty() && a > ends.top())
                ends.pop();
            ends.push(b);
        }
        return ends.size();
    }
};


int main() {

    vector<vector<int>> intervals1 = {{5, 10}, {6, 8}, {1, 5}, {2, 3}, {1, 10}};
    cout << Solution().minGroups(intervals1) << '\n';
    // 3

    vector<vector<int>> intervals2 = {{1, 3}, {5, 6}, {8, 10}, {11, 13}};
    cout << Solution().minGroups(intervals2) << '\n';
    // 1

    return 0;
}
