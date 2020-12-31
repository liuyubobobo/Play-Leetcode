/// Source : https://leetcode.com/problems/majority-element/description/
/// Author : liuyubobobo
/// Time   : 2017-11-14

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/// Divide and Conquer
/// Time Complexity: O(nlogn)
/// Space Complexity: O(lgn) for recursive call
class Solution {

public:
    int majorityElement(vector<int>& nums) {

        assert(nums.size() > 0);

        return majorityElement(nums, 0, nums.size() - 1);
    }

private:
    int majorityElement(const vector<int>& nums, int left, int right){

        int len = right - left + 1;
        if(len <= 2){
            assert(len >= 1);
            return nums[left];
        }

        int mid = (left + right) / 2;
        int leftMajority = majorityElement(nums, left, mid);
        int rightMajority = majorityElement(nums, mid + 1, right);

        if(leftMajority == rightMajority)
            return leftMajority;

        int leftMajorityCnt = occurance(nums, left, mid, leftMajority);
        int rightMajorityCnt = occurance(nums, mid + 1, right, rightMajority);

        assert(leftMajority != rightMajority);
        return leftMajorityCnt > rightMajorityCnt ? leftMajority : rightMajority;
    }

    int occurance(const vector<int>& nums, int l, int r, int target){
        int cnt = 0;
        for(int i = l ; i <= r ; i ++)
            if(nums[i] == target)
                cnt ++;
        return cnt;
    }
};

int main() {

    int nums[1] = {1};
    vector<int> vec(nums, nums + 1);
    cout << Solution().majorityElement(vec) << endl;
    return 0;
}