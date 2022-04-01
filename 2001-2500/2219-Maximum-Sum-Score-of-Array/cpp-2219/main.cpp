/// Source : https://leetcode.com/problems/maximum-sum-score-of-array/
/// Author : liuyubobobo
/// Time   : 2022-04-01

#include <iostream>
#include <vector>

using namespace std;


/// Linear Scan
/// Time Complexity: O(n)
/// Space Compelxity: O(1)
class Solution {
public:
    long long maximumSumScore(vector<int>& nums) {

        long long tail = 0;
        for(int e: nums) tail += e;

        long long front = nums[0];
        long long res = max(front, tail);
        for(int i = 1; i < nums.size(); i ++){
            front += nums[i];
            tail -= nums[i - 1];
            res = max(res, max(front, tail));
        }
        return res;
    }
};


int main() {

    return 0;
}
