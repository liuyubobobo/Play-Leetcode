/// Source : https://leetcode.com/problems/the-employee-that-worked-on-the-longest-task/
/// Author : liuyubobobo
/// Time   : 2022-10-08

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {

        int max_t = -1, res = INT_MAX;
        int cur = 0;
        for(const vector<int>& log: logs){
            int id = log[0], t = log[1];
            if(t - cur > max_t)
                res = id, max_t = t - cur;
            else if(t - cur == max_t)
                res = min(res, id);
            cur = t;
        }
        return res;
    }
};


int main() {

    vector<vector<int>> logs1 = {{0, 3}, {2, 5}, {0, 9}, {1, 15}};
    cout << Solution().hardestWorker(10, logs1) << '\n';
    // 1

    return 0;
}
