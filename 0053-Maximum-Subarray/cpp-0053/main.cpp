/// Source : https://leetcode.com/problems/maximum-subarray/
/// Author : liuyubobobo
/// Time   : 2020-04-03

#include <iostream>
#include <vector>

using namespace std;


/// Classical DP: Kadane's algorithm
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int res = *max_element(nums.begin(), nums.end());
        if(res < 0) return res;

        int sum = 0;
        for(int e: nums){
            if(sum + e < 0) sum = 0;
            else{res = max(res, sum + e); sum += e;}
        }
        return res;
    }
};


int main() {

    return 0;
}
