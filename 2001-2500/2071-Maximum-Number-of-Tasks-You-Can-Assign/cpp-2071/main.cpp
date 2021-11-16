/// Source : https://leetcode.com/problems/maximum-number-of-tasks-you-can-assign/
/// Author : liuyubobobo
/// Time   : 2021-11-16

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Binary Serch + Greedy
/// Time Complexity: O(log(min(m, n)) * mlogn), where m = |tasks|, n = |workers|
/// Space Complexity: O(n)
class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {

        sort(tasks.begin(), tasks.end());
        multiset<int> worker_set(workers.begin(), workers.end());

        int l = 0, r = tasks.size();
        while(l < r){
            int mid = (l + r + 1) / 2;
            if(ok(tasks, worker_set, mid, pills, strength))
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }

private:
    bool ok(const vector<int>& tasks, multiset<int> workers, int k, int pills, int str){

        for(int i = k - 1; i >= 0; i --)
            if(!workers.empty() && *workers.rbegin() >= tasks[i])
                workers.erase(prev(workers.end()));
            else if(pills){
                auto it = workers.lower_bound(tasks[i] - str);
                if(it == workers.end()) return false;
                workers.erase(it);
                pills --;
            }
            else return false;
        return true;
    }
};

int main() {

    vector<int> task1 = {3, 2, 1}, workers1 = {0, 3, 3};
    cout << Solution().maxTaskAssign(task1, workers1, 1, 1) << endl;
    // 3

    vector<int> task2 = {5, 4}, workers2 = {0, 0, 0};
    cout << Solution().maxTaskAssign(task2, workers2, 1, 5) << endl;
    // 1

    vector<int> task3 = {10, 15, 30}, workers3 = {0, 10, 10, 10, 10};
    cout << Solution().maxTaskAssign(task3, workers3, 3, 10) << endl;
    // 2

    vector<int> task4 = {5, 9, 8, 5, 9}, workers4 = {1, 6, 4, 2, 6};
    cout << Solution().maxTaskAssign(task4, workers4, 1, 5) << endl;
    // 3

    vector<int> task5 = {74,41,64,20,28,52,30,4,4,63}, workers5 = {38};
    cout << Solution().maxTaskAssign(task5, workers5, 0, 68) << endl;
    // 1

    return 0;
}
