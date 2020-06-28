/// Source : https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/
/// Author : liuyubobobo
/// Time   : 2020-06-27

#include <iostream>
#include <vector>

using namespace std;


/// Sorting + Binary Search + Fast Pow
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {

private:
    const long long MOD = 1e9 + 7;

public:
    int numSubseq(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        long long res = 0;
        for(int i = 0; i < nums.size(); i ++){
            vector<int>::iterator iter = upper_bound(nums.begin() + i, nums.end(), target - nums[i]);
            int x = iter - (nums.begin() + i) - 1;
            if(x >= 0) res = (res + (mypow(2, x))) % MOD;
        }
        return res;
    }

    long long mypow(int a, int b){

        if(b == 0) return 1ll;
        if(b == 1) return a;

        long long x = mypow(a, b / 2);
        long long res = x * x % MOD;
        if(b % 2) res = res * a % MOD;
        return res;
    }
};


int main() {

    vector<int> nums1 = {3,5,6,7};
    cout << Solution().numSubseq(nums1, 9) << endl;
    // 4

    vector<int> nums2 = {3,3,6,8};
    cout << Solution().numSubseq(nums2, 10) << endl;
    // 6

    vector<int> nums3 = {2,3,3,4,6,7};
    cout << Solution().numSubseq(nums3, 12) << endl;
    // 61

    vector<int> nums4 = {5,2,4,1,7,6,8};
    cout << Solution().numSubseq(nums4, 16) << endl;
    // 127

    return 0;
}
