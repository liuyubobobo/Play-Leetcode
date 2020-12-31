/// Source : https://leetcode.com/problems/search-for-a-range/description/
/// Author : liuyubobobo
/// Time   : 2017-11-16

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

/// Using STL lower_bounf and upper_bound
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        vector<int>::iterator lowerIter = lower_bound(nums.begin(), nums.end(), target);
        int first = -1;
        if(lowerIter != nums.end() && *lowerIter == target)
            first = lowerIter - nums.begin();

        vector<int>::iterator upperIter = upper_bound(nums.begin(), nums.end(), target);
        int last = -1;
        if(upperIter == nums.end() && nums.size() > 0 && nums.back() == target)
            last = nums.size() - 1;
        else if(upperIter != nums.end() && *(upperIter - 1) == target)
            last = upperIter - nums.begin() - 1;

        if(first == -1)
            assert(last == -1);

        int res[2] = {first, last};
        return vector<int>(res, res + 2);
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