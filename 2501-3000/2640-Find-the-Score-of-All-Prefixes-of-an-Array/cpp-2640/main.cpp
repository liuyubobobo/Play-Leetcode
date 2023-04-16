/// Source : https://leetcode.com/problems/find-the-score-of-all-prefixes-of-an-array/description/
/// Author : liuyubobobo
/// Time   : 2023-04-15

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {

        int n = nums.size();

        vector<long long> pre_max(n, nums[0]);
        for(int i = 1; i < n; i ++) pre_max[i] = max(pre_max[i - 1], 0ll + nums[i]);

        vector<long long> conver(n);
        for(int i = 0; i < n; i ++) conver[i] = nums[i] + pre_max[i];

        vector<long long> res(n, conver[0]);
        for(int i = 1; i < n; i ++) res[i] = res[i - 1] + conver[i];
        return res;
    }
};


int main() {

    return 0;
}
