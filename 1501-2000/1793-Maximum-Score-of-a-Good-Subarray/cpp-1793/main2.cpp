/// Source : https://leetcode.com/problems/maximum-score-of-a-good-subarray/
/// Author : liuyubobobo
/// Time   : 2021-03-14

#include <iostream>
#include <vector>

using namespace std;


/// Two Pointers and Greedy
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {

        int l = k - 1, r = k + 1;
        int res =nums[k], curmin = nums[k];
        while(l >= 0 || r < nums.size()){
            if(l < 0){
                curmin = min(curmin, nums[r]);
                r ++;
            }
            else if(r >= nums.size()){
                curmin = min(curmin, nums[l]);
                l --;
            }
            else if(nums[l] > nums[r]){
                curmin = min(curmin, nums[l]);
                l --;
            }
            else{
                curmin = min(curmin, nums[r]);
                r ++;
            }
            res = max(res, curmin * (r - l + 1));
        }
        return res;
    }
};


int main() {

    vector<int> nums1 = {1, 4, 3, 7, 4, 5};
    cout << Solution().maximumScore(nums1, 3) << endl;
    // 15

    vector<int> nums2 = {5,5,4,5,4,1,1,1};
    cout << Solution().maximumScore(nums2, 0) << endl;
    // 20

    vector<int> nums3 = {6569,9667,3148,7698,1622,2194,793,9041,1670,1872};
    cout << Solution().maximumScore(nums3, 5) << endl;
    // 9732

    return 0;
}
