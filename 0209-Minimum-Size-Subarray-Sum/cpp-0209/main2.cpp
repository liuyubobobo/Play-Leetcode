/// https://leetcode.com/problems/minimum-size-subarray-sum/description/
/// Author : liuyubobobo
/// Time   : 2019-03-03

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;


// Brute Force + Greedy
// Time Complexity: O(n^2)
// Space Complexity: O(1)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {

        assert(s > 0);

        int res = nums.size() + 1;
        for(int l = 0 ; l < nums.size() ; l ++) {
            int sum = 0;
            for (int r = l; r < nums.size(); r++){
                sum += nums[r];
                if(sum >= s){
                    res = min(res, r - l + 1);
                    break;
                }
            }
        }

        return res == nums.size() + 1 ? 0 : res;
    }
};


int main() {

    vector<int> nums1 = {2, 3, 1, 2, 4, 3};
    int s1 = 7;
    cout << Solution().minSubArrayLen(s1, vec1) << endl;

    return 0;
}