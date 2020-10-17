/// Source : https://leetcode.com/problems/number-of-ways-where-square-of-number-is-equal-to-product-of-two-numbers/
/// Author : liuyubobobo
/// Time   : 2020-09-05

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// HashMap
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<long long, int> p1;
        for(int i = 0; i < nums1.size(); i ++)
            for(int j = i + 1; j < nums1.size(); j ++)
                p1[(long long)nums1[i] * (long long)nums1[j]] ++;

        unordered_map<long long, int> p2;
        for(int i = 0; i < nums2.size(); i ++)
            for(int j = i + 1; j < nums2.size(); j ++)
                p2[(long long)nums2[i] * (long long)nums2[j]] ++;

        int res = 0;
        for(int e: nums1)
            res += p2[(long long)e * (long long)e];

        for(int e: nums2)
            res += p1[(long long)e * (long long)e];

        return res;
    }
};



int main() {

    vector<int> nums11 = {7,4}, nums12 = {5,2,8,9};
    cout << Solution().numTriplets(nums11, nums12) << endl;
    // 1

    vector<int> nums21 = {1,1}, nums22 = {1,1,1};
    cout << Solution().numTriplets(nums21, nums22) << endl;
    // 9

    vector<int> nums31 = {7,7,8,3}, nums32 = {1,2,9,7};
    cout << Solution().numTriplets(nums31, nums32) << endl;
    // 2

    vector<int> nums41 = {4,7,9,11,23}, nums42 = {3,5,1024,12,18};
    cout << Solution().numTriplets(nums41, nums42) << endl;
    // 0

    return 0;
}
