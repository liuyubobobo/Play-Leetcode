/// Source : https://leetcode.com/problems/total-cost-to-hire-k-workers/description/
/// Author : liuyubobobo
/// Time   : 2022-11-05

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;


/// Using MinHeap
/// Time Complexity: O((candidates + k) * log(candidates))
/// Space Complexity: O(candidates)
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {

        int n = costs.size();

        priority_queue<int, vector<int>, greater<>> front_pq, tail_pq;
        for(int i = 0; i < candidates; i ++) front_pq.push(costs[i]);
        for(int i = n - 1; i >= n - candidates && i >= candidates; i --) tail_pq.push(costs[i]);

        int front = candidates, tail = n - candidates - 1;
        long long res = 0;
        for(int i = 0; i < k; i ++){
            int front_min = front_pq.empty() ? INT_MAX : front_pq.top();
            int tail_min = tail_pq.empty() ? INT_MAX : tail_pq.top();
            if(front_min <= tail_min){
                res += front_min;
                front_pq.pop();
                if(front <= tail) front_pq.push(costs[front ++]);
            }
            else{
                res += tail_min;
                tail_pq.pop();
                if(front <= tail) tail_pq.push(costs[tail --]);
            }
        }
        return res;
    }
};


int main() {

    vector<int> costs1 = {17,12,10,2,7,2,11,20,8};
    cout << Solution().totalCost(costs1, 3, 4) << '\n';
    // 11

    vector<int> costs2 = {57,33,26,76,14,67,24,90,72,37,30};
    cout << Solution().totalCost(costs2, 11, 2) << '\n';
    // 526

    return 0;
}
