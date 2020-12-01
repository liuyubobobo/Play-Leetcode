/// Source : https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/
/// Author : liuyubobobo
/// Time   : 2020-11-30

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// Min Heap for n pointers
/// Time Complexity: O(nlogn)
/// Space Compelxity: O(n)
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {

        int n = nums.size();
        vector<int> next(n, 0);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int curmax = INT_MIN;
        for(int i = 0; i < n; i ++)
            pq.push({nums[i][0], i}), curmax = max(curmax, nums[i][0]);

        int resl = -1e9, resr = 1e9;
        while(true){

            if(curmax - pq.top().first < resr - resl)
                resl = pq.top().first, resr = curmax;

            int index = pq.top().second;
            pq.pop();

            next[index] ++;
            if(next[index] >= nums[index].size()) break;

            pq.push({nums[index][next[index]], index});
            curmax = max(curmax, nums[index][next[index]]);
        }
        return {resl, resr};
    }
};


int main() {

    return 0;
}
