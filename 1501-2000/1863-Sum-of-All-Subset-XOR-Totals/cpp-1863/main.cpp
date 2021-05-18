/// Source : https://leetcode.com/problems/sum-of-all-subset-xor-totals/
/// Author : liuyubobobo
/// Time   : 2021-05-15

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n * 2^n)
/// Space Complexity: O(1)
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {

        int n = nums.size(), res = 0;
        for(int state = 1; state < (1 << n); state ++){

            int t = 0;
            for(int k = 0; k < n; k ++)
                if(state & (1 << k)) t ^= nums[k];
            res += t;
        }
        return res;
    }
};

int main() {

    return 0;
}
