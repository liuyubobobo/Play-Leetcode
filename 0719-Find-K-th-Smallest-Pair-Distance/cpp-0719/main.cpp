/// Source : https://leetcode.com/problems/find-k-th-smallest-pair-distance/description/
/// Author : liuyubobobo
/// Time   : 2017-10-28

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

/// Time Complexity: O(nlogn + n^2 + W)
/// Space Complexity: O(W), where W = max(nums) - min(nums)
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {

        int dis[1000000];
        for(int i = 0 ; i < 1000000 ; i ++)
            dis[i] = 0;

        sort(nums.begin(), nums.end());
        for(int i = 0 ; i < nums.size() ; i ++)
            for(int j = i + 1 ; j < nums.size() ; j ++){
                //cout << nums[j] - nums[i] << endl;
                dis[nums[j]-nums[i]] ++;
            }

        int index = 0;
        for(int i = 0 ; i < 1000000 ; i ++){
            index += dis[i];
            if(k <= index)
                return i;
        }

        return -1;
    }
};

int main() {

    int nums1[] = {1, 3, 1};
    int k1 = 1;
    vector<int> vec1(nums1, nums1 + sizeof(nums1)/sizeof(int));
    cout << Solution().smallestDistancePair(vec1, k1) << endl;
    // 0

    // ---

    int nums2[] = {1, 6, 1};
    int k2 = 3;
    vector<int> vec2(nums2, nums2 + sizeof(nums2)/sizeof(int));
    cout << Solution().smallestDistancePair(vec2, k2) << endl;
    // 5

    return 0;
}