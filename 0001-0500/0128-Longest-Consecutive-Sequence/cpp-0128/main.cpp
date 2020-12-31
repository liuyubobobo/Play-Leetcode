/// Source : https://leetcode.com/problems/longest-consecutive-sequence/description/
/// Author : liuyubobobo
/// Time   : 2017-11-03

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/// Sort
/// Remove duplicate elements and get result
///
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.size() == 0)
            return 0;

        sort(nums.begin(), nums.end());
        int len = 0;
        for(int start = 0, i = start + 1 ; i <= nums.size() ; ){
            if(i == nums.size() || nums[i] != nums[start]){
                nums[len++] = nums[start];
                start = i;
                i = start + 1;
            }
            else
                i ++;
        }

//        printVec(nums);
//        cout << "len = " << len << endl;

        int res = 1;
        for(int start = 0, i = start + 1 ; i <= len ;){
            if(i == nums.size() || nums[i-1] + 1 != nums[i] ){
                res = max(res, i-start);
                start = i;
                i = start + 1;
            }
            else
                i ++;
        }

        return res;
    }

private:
    void printVec(const vector<int>& vec){
        for(int e: vec)
            cout << e << " ";
        cout << endl;
    }
};

int main() {

    int nums1[6] = {100, 4, 200, 1, 3, 2};
    vector<int> vec1(nums1, nums1 + sizeof(nums1)/sizeof(int));
    cout << Solution().longestConsecutive(vec1) << endl;
    // 4

    // ---

    int nums2[4] = {1, 2, 0, 1};
    vector<int> vec2(nums2, nums2 + sizeof(nums2)/sizeof(int));
    cout << Solution().longestConsecutive(vec2) << endl;
    // 3

    return 0;
}