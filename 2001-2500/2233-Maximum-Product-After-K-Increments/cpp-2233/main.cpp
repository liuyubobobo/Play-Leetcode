/// Source : https://leetcode.com/problems/maximum-product-after-k-increments/
/// Author : liuyubobobo
/// Time   : 2022-04-10

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// Using PQ
/// Time Complexity: O(klogn + nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {

        priority_queue<int, vector<int>, greater<int>> pq;
        for(int e: nums) pq.push(e);

        while(k --){
            int e = pq.top(); pq.pop();
            e ++;
            pq.push(e);
        }

        long long res = 1ll, MOD = 1e9 + 7;
        while(!pq.empty()){
            int e = pq.top(); pq.pop();
            res *= e;
            res %= MOD;
        }
        return res;
    }
};


int main() {

    return 0;
}
