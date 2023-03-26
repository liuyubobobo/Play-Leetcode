/// Source : https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/description/
/// Author : liuyubobobo
/// Time   : 2023-03-25

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// Using PQ
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    long long findScore(vector<int>& nums) {

        int n = nums.size();
        vector<bool> visited(n, false);

        long long score = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        for(int i = 0; i < n; i++) pq.push({nums[i], i});

        while(!pq.empty()) {
            auto [val, idx] = pq.top();
            pq.pop();

            if(visited[idx]) continue;
            visited[idx] = true;
            if(idx > 0) visited[idx - 1] = true;
            if(idx + 1 < n) visited[idx + 1] = true;

            score += val;
        }
        return score;
    }
};


int main() {

    return 0;
}
