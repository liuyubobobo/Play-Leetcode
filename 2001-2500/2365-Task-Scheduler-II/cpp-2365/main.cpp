/// Source : https://leetcode.com/problems/task-scheduler-ii/
/// Author : liuyubobobo
/// Time   : 2022-08-10

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// DP
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {

        map<int, long long> last;
        long long cur = 1;
        for(int task: tasks){
            if(!last.count(task)){
                last[task] = cur;
                cur ++;
                continue;
            }

            long long pre = last[task];
            long long next = max(pre + space + 1, cur);
            last[task] = next;
            cur = next + 1;
        }
        return cur - 1;
    }
};


int main() {

    vector<int> tasks1 = {1, 2, 1, 2, 3, 1};
    cout << Solution().taskSchedulerII(tasks1, 3) << '\n';
    // 9

    return 0;
}
