/// Source : https://leetcode.com/problems/max-consecutive-ones/description/
/// Author : liuyubobobo
/// Time   : 2018-06-16

#include <iostream>
#include <vector>

using namespace std;

/// Ad-Hoc
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int res = 0;
        int start = firstOne(nums, 0);
        for(int i = start + 1 ; i <= nums.size() ; ){
            if(i == nums.size() || nums[i] != 1){
                // cout << i - start << endl;
                res = max(res, i - start);
                start = firstOne(nums, i);
                i = start + 1;
            }
            else
                i ++;
        }
        return res;
    }

private:
    int firstOne(const vector<int>& nums, int startIndex){
        for(int i = startIndex ; i < nums.size() ; i ++)
            if(nums[i] == 1)
                return i;
        return nums.size();
    }
};


int main() {

    vector<int> nums = {1, 1, 0, 1, 1, 1};
    cout << Solution().findMaxConsecutiveOnes(nums) << endl;
    return 0;
}