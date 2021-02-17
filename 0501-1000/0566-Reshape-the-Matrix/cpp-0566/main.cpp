/// Source : https://leetcode.com/problems/reshape-the-matrix/
/// Author : liuyubobobo
/// Time   : 2021-02-16

#include <iostream>
#include <vector>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(R * C)
/// Space Complexity: O(1)
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {

        int oR = nums.size(), oC = nums[0].size();
        if(r * c != oR * oC) return nums;

        vector<vector<int>> res(r, vector<int>(c));
        for(int i = 0; i < oR; i ++)
            for(int j = 0; j < oC; j ++)
                res[(i * oC + j) / c][(i * oC + j) % c] = nums[i][j];
        return res;
    }
};


int main() {

    return 0;
}
