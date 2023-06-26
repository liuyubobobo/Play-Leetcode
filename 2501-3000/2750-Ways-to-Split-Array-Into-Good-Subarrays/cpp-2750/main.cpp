/// Source : https://leetcode.com/problems/ways-to-split-array-into-good-subarrays/description/
/// Author : liuyubobobo
/// Time   : 2023-06-25

#include <iostream>
#include <vector>

using namespace std;


/// Math
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

private:
    long long MOD = 1e9 + 7;

public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {

        vector<int> pos;
        for(int i = 0; i < nums.size(); i ++) if(nums[i] == 1) pos.push_back(i);

        if(pos.empty()) return 0;

        long long res = 1;
        for(int i = 0; i + 1 < pos.size(); i ++){
            long long t = pos[i + 1] - pos[i];
            res = res * t % MOD;
        }
        return res;
    }
};


int main() {

    return 0;
}
