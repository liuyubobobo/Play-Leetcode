/// Source : https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/
/// Author : liuyubobobo
/// Time   : 2022-11-05

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Sliding Window
/// Time Complexity: O(n)
/// Space Complexity: O(max_nums)
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        int n = nums.size();
        vector<int> f(1e5 + 1);
        int not_unique = 0;
        long long sum = 0, res = 0;

        for(int i = 0; i < n; i ++){
            sum += nums[i];
            f[nums[i]] ++;
            if(f[nums[i]] == 2) not_unique ++;

            if(i >= k - 1){
                if(not_unique == 0) res = max(res, sum);

                sum -= nums[i - (k - 1)];
                f[nums[i - (k - 1)]] --;
                if(f[nums[i - (k - 1)]] == 1) not_unique --;
            }
        }

        return res;
    }
};


int main() {

    return 0;
}
