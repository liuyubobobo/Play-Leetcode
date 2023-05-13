/// Source : https://leetcode.com/problems/sum-in-a-matrix/description/
/// Author : liuyubobobo
/// Time   : 2023-05-13

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Simulation
/// Time Complexity: O(R * ClogC)
/// Space Complexity: O(1)
class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {

        for(vector<int>& v: nums) sort(v.begin(), v.end());

        int res = 0;
        for(int c = 0; c < nums[0].size(); c++) {
            int maxv = 0;
            for(int r = 0; r < nums.size(); r++) maxv = max(maxv, nums[r][c]);
            res += maxv;
        }
        return res;
    }
};


int main() {

    return 0;
}
