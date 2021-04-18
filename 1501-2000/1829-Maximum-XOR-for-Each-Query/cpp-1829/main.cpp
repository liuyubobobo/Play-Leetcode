/// Source : https://leetcode.com/problems/maximum-xor-for-each-query/
/// Author : liuyubobobo
/// Time   : 2021-04-17

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(n * maxBit)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {

        vector<int> pow2(30, 1);
        for(int i = 1; i < 30; i ++) pow2[i] = pow2[i - 1] * 2;

        vector<int> res;
        int x = 0;
        for(int num: nums){
            x ^= num;
            res.push_back(solve(x, maximumBit, pow2));
        }

        reverse(res.begin(), res.end());
        return res;
    }

private:
    int solve(int x, int maximumBit, const vector<int>& pow2){

        int res = 0;
        for(int i = 0; i < maximumBit; i ++)
            res += (!(x % 2)) * pow2[i], x /= 2;
        return res;
    }
};


int main() {

    return 0;
}
