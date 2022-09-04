/// Source : https://leetcode.com/problems/longest-nice-subarray/
/// Author : liuyubobobo
/// Time   : 2022-09-03

#include <iostream>
#include <vector>

using namespace std;


/// Sliding Window
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {

        int n = nums.size();

        vector<int> cur(30, 0);
        int res = 0, l = 0, r = -1;
        while(l < n){
            if(r + 1 < n && ok(cur, nums[r + 1]))
                add(cur, nums[++r]);
            else
                remove(cur, nums[l ++]);
            res = max(res, r - l + 1);
        }
        return res;
    }

private:
    bool ok(const vector<int>& bits, int x){

        for(int p = 0; p < 30; p ++)
            if(bits[p] + ((x >> p) & 1) > 1) return false;
        return true;
    }

    void add(vector<int>& bits, int x){
        for(int p = 0; p < 30; p ++)
            bits[p] += ((x >> p) & 1);
    }

    void remove(vector<int>& bits, int x){
        for(int p = 0; p < 30; p ++)
            bits[p] -= ((x >> p) & 1);
    }
};


int main() {

    vector<int> nums1 = {1, 3, 8, 48, 10};
    cout << Solution().longestNiceSubarray(nums1) << '\n';
    // 3

    vector<int> nums2 = {3, 1, 5, 11, 13};
    cout << Solution().longestNiceSubarray(nums2) << '\n';
    // 1

    return 0;
}
