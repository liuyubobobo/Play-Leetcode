/// Source : https://leetcode.com/problems/find-subarrays-with-equal-sum/
/// Author : liuyubobobo
/// Time   : 2022-09-03

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n^2)
/// Space Complexity: O(1)
class Solution {
public:
    bool findSubarrays(vector<int>& nums) {

        int n = nums.size();
        for(int start = 0; start + 1 < n; start ++){
            int t = nums[start] + nums[start + 1];
            for(int i = start + 1; i + 1 < n; i ++)
                if(t == nums[i] + nums[i + 1]) return true;
        }
        return false;
    }
};


int main() {


    return 0;
}
