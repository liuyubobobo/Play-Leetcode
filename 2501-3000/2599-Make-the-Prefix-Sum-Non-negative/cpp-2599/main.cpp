/// Source : https://leetcode.com/problems/make-the-prefix-sum-non-negative/description/
/// Author : liuyubobobo
/// Time   : 2023-03-24

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cassert>

using namespace std;


/// Greedy
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    int makePrefSumNonNegative(vector<int>& nums) {

        int n = nums.size();

        vector<long long> last;
        priority_queue<long long, vector<long long>, greater<>> pq;
        long long cur_presum = 0;
        for(int i = 0; i < n; i ++){

            cur_presum += nums[i];
            if(nums[i] < 0) pq.push(nums[i]);

            while(cur_presum < 0){
                long long t = pq.top(); pq.pop();
                last.push_back(t), cur_presum -= t;
            }

        }
        return last.size();
    }
};


int main() {

    return 0;
}
