/// Source : https://leetcode.com/problems/longest-consecutive-sequence/description/
/// Author : liuyubobobo
/// Time   : 2017-11-03

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/// Using Set
///
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.size() == 0)
            return 0;

        unordered_set<int> unique_nums(nums.begin(), nums.end());

        int res = 1;
        for(int num: unique_nums) {
            if(unique_nums.find(num - 1) == unique_nums.end()){
                int offset = 1;
                while(unique_nums.find(num + offset) != unique_nums.end())
                    offset ++;
                res = max(res, offset);
            }
        }

        return res;
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