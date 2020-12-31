/// Source : https://leetcode.com/problems/3sum-smaller/
/// Author : liuyubobobo
/// Time   : 2016-12-05
#include <iostream>
#include <vector>
#include <cassert>
#include <stdexcept>

using namespace std;


/// Two Pointers
/// Sort the entire numbers first.
/// For every number nums[i],
/// using two pointers technique to find indexes j and k,
/// which makes nums[i] + nums[j] + nums[k] < target.
/// Then, we can use j and k to calculate how many pairs can be got between nums[j] and nums[k].
///
/// Time Complexity: O(nlogn) + O(n^2)
/// Space Complexity: O(1)
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {

        // There're testcases which the nums.size < 3
        //assert(nums.size() >= 3);
        if(nums.size() < 3)
            return 0;

        sort(nums.begin(), nums.end());

        int res = 0;
        for(int i = 0 ; i < nums.size() - 2 ; i ++){

            int j = i + 1, k = nums.size() - 1;
            while(j < k){

                if(nums[i] + nums[j] + nums[k] < target){
                    res += (k - j);
                    j ++;
                }
                else
                    k --;
            }
        }
        return res;
    }
};


int main() {

    vector<int> nums1 = {-2, 0, 1, 3};
    int target1 = 4;
    cout << Solution().threeSumSmaller(nums1, target1) << endl;

    return 0;
}