/// Source : https://leetcode.com/problems/find-the-difference-of-two-arrays/
/// Author : liuyubobobo
/// Time   : 2022-03-26

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Brute Force
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {

        set<int> res1;
        for(int e: nums1)
            if(find(nums2.begin(), nums2.end(), e) == nums2.end()) res1.insert(e);

        set<int> res2;
        for(int e: nums2)
            if(find(nums1.begin(), nums1.end(), e) == nums1.end()) res2.insert(e);

        return {vector<int>(res1.begin(), res1.end()), vector<int>(res2.begin(), res2.end())};
    }
};


int main() {

    return 0;
}
