/// Source : https://leetcode.com/problems/search-for-a-range/description/
/// Author : liuyubobobo
/// Time   : 2017-11-16
/// Updated: 2021-04-29

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/// Binary Search
/// Time Complexity: O(logn)
/// Space Complexity: O(1)
class Solution {

public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int lowerIndex = firstOccurance(nums, target);
        int first = -1;
        if(lowerIndex != nums.size() && nums[lowerIndex] == target)
            first = lowerIndex;
        else return {-1, -1};
        // cout << "first = " << first << endl;

        int upperIndex = lastOccurance(nums, target);
        int last = -1;
        if(upperIndex != 0){
            upperIndex --;
            last = upperIndex;
        }
        else return {-1, -1};

        return {first, last};
    }

private:
    // same to lower_bound
    int firstOccurance(const vector<int>& nums, int target){

        int l = 0, r = nums.size();
        while(l != r){
            int mid = l + (r - l) / 2;
            if(nums[mid] < target)
                l = mid + 1;
            else    // nums[mid] >= target
                r = mid;
        }
        return l;
    }

    // same to upper_bound
    int lastOccurance(const vector<int>& nums, int target){

        int l = 0, r = nums.size();
        while(l != r){
            int mid = l + (r - l) / 2;
            if(nums[mid] <= target)
                l = mid + 1;
            else    // nums[mid] > target
                r = mid;
        }
        return l;
    }
};


void printVec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    int nums1[6] = {5, 7, 7, 8, 8, 10};
    int target1 = 8;
    vector<int> vec1(nums1, nums1 + sizeof(nums1) / sizeof(int));

    printVec(Solution().searchRange(vec1, target1));
    // 3, 4

    // ---

    int nums2[1] = {1};
    int target2 = 0;
    vector<int> vec2(nums2, nums2 + sizeof(nums2) / sizeof(int));

    printVec(Solution().searchRange(vec2, target2));
    // -1, -1

    // ---

    int nums3[1] = {1};
    int target3 = 1;
    vector<int> vec3(nums3, nums3 + sizeof(nums3) / sizeof(int));

    printVec(Solution().searchRange(vec3, target3));
    // 0, 0

    // ---
    vector<int> vec4;
    printVec(Solution().searchRange(vec4, 0));
    // -1, -1

    return 0;
}