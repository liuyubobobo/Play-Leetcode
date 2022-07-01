/// Source : https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs-ii/
/// Author : liuyubobobo
/// Time   : 2022-07-01

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Greedy
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    int minimumTime(vector<int>& jobs, vector<int>& workers) {

        sort(jobs.begin(), jobs.end());
        sort(workers.begin(), workers.end());

        int res = 0;
        for(int i = 0; i < jobs.size(); i ++)
            res = max(res, jobs[i] / workers[i] + !!(jobs[i] % workers[i]));
        return res;
    }
};


int main() {

    vector<int> jobs1 = {5, 2, 4}, workers1 = {1, 7, 5};
    cout << Solution().minimumTime(jobs1, workers1) << '\n';
    // 2

    return 0;
}
