/// Source : https://leetcode.com/problems/total-hamming-distance/
/// Author : liuyubobobo
/// Time   : 2020-05-25

#include <iostream>
#include <vector>

using namespace std;


/// Count one for every bits position
/// Time Complexity: O(nlog(num))
/// Space Complexity: O(1)
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {

        vector<int> cnt(32, 0);
        for(int e: nums){
            int i = 0;
            while(e) {
                if(e % 2) cnt[i] ++;
                i ++, e /= 2;
            }
        }

        int res = 0;
        for(int i = 0; i < 32; i ++) res += cnt[i] * (nums.size() - cnt[i]);
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
