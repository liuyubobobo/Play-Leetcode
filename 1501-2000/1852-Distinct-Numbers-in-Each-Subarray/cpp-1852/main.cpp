/// Source : https://leetcode.com/problems/distinct-numbers-in-each-subarray/
/// Author : liuyubobobo
/// Time   : 2021-05-06

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Sliding Window
/// Time Complexity: O(n)
/// Space Complexity: O(k)
class Solution {
public:
    vector<int> distinctNumbers(vector<int>& nums, int k) {

        unordered_map<int, int> f;
        vector<int> res;

        for(int i = 0; i < k - 1; i ++)
            f[nums[i]] ++;

        for(int i = k - 1; i < nums.size(); i ++){
            f[nums[i]] ++;
            res.push_back(f.size());
            f[nums[i - (k - 1)]] --;
            if(f[nums[i - (k - 1)]] == 0) f.erase(nums[i - (k - 1)]);
        }
        return res;
    }
};


int main() {

    return 0;
}
