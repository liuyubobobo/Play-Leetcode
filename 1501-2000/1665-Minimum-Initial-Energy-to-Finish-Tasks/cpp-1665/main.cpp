/// Source : https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/
/// Author : liuyubobobo
/// Time   : 2020-11-21

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Binary Search
/// Time Complexity: O(nlogn + nlog|max_int|)
/// Space Complexity: O(1)
class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {

        sort(tasks.begin(), tasks.end(), [](const vector<int>& v1, const vector<int>& v2){

            if(v1[1] - v1[0] != v2[1] - v2[0])
                return v1[1] - v1[0] > v2[1] - v2[0];

            return v1[1] > v2[1];
        });

        int l = 0, r = 2e9;
        while(l < r){
            int mid = (l + r) / 2;
            if(ok(tasks, mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }

private:
    bool ok(const vector<vector<int>>& v, int k){

        for(const vector<int>& e: v){
            if(k < e[1]) return false;
            k -= e[0];
        }
        return true;
    }
};


int main() {

    vector<vector<int>> tasks1 = {{1, 2}, {2, 4}, {4, 8}};
    cout << Solution().minimumEffort(tasks1) << endl;
    // 8

    vector<vector<int>> tasks2 = {{1, 3}, {2, 4}, {10, 11}, {10, 12}, {8, 9}};
    cout << Solution().minimumEffort(tasks2) << endl;
    // 32

    vector<vector<int>> tasks3 = {{1, 7}, {2, 8}, {3, 9}, {4, 10}, {5, 11}, {6, 12}};
    cout << Solution().minimumEffort(tasks3) << endl;
    // 27

    vector<vector<int>> tasks4 = {{1, 2}, {1, 7}, {2, 3}, {5, 9}, {2, 2}};
    cout << Solution().minimumEffort(tasks4) << endl;
    // 11

    return 0;
}
