/// Source : https://leetcode.com/problems/concatenation-of-array/
/// Author : liuyubobobo
/// Time   : 2021-07-10

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {

        int n = nums.size();
        vector<int> res(2 * n);
        for(int i = 0; i < n; i ++)
            res[i] = res[i + n] = nums[i];
        return res;
    }
};


int main() {

    return 0;
}
