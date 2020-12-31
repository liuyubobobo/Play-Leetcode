/// Source : https://leetcode.com/problems/total-hamming-distance/
/// Author : liuyubobobo
/// Time   : 2020-05-25

#include <iostream>
#include <vector>

using namespace std;


/// Count one and zero for every bits position
/// Time Complexity: O(nlog(num))
/// Space Complexity: O(1)
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {

        vector<vector<int>> cnt(32, vector<int>(2, 0));
        for(int e: nums){
            int i = 0;
            while(e) cnt[i ++][e % 2] ++, e /= 2;
            while(i < 32) cnt[i ++][0] ++;
        }

        int res = 0;
        for(int i = 0; i < 32; i ++) res += cnt[i][0] * cnt[i][1];
        return res;
    }
};


int main() {

    vector<int> nums1 = {4, 14, 2};
    cout << Solution().totalHammingDistance(nums1) << endl;
    // 6

    vector<int> nums2 = {1337};
    cout << Solution().totalHammingDistance(nums2) << endl;
    // 0

    return 0;
}
