/// Source : https://leetcode.com/problems/left-and-right-sum-differences/description/
/// Author : liuyubobobo
/// Time   : 2023-02-27

#include <iostream>
#include <vector>

using namespace std;


/// Presum
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {

        int n = nums.size();
        vector<int> presum(n + 1, 0);
        for(int i = 0; i < n; i ++) presum[i + 1] = presum[i] + nums[i];

        vector<int> res(n, 0);
        for(int i = 0; i < n; i ++){
            int left = presum[i];
            int right = presum[n] - presum[i + 1];
            res[i] = abs(right - left);
        }
        return res;
    }
};


int main() {

    return 0;
}
