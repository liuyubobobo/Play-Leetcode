/// Source : https://leetcode.com/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1/
/// Author : liuyubobobo
/// Time   : 2023-04-30

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;


/// Greedy
/// Time Complexity: O(n^3)
/// Space Complexity: O(1)
class Solution {
public:
    int minOperations(vector<int>& nums) {

        int n = nums.size(), g = gcd(nums, 0, n - 1);
        if(g > 1) return -1;

        int one_cnt = count(nums.begin(), nums.end(), 1);
        if(one_cnt) return n - one_cnt;

        int min_len = n;
        for(int s = 0; s < n; s ++)
            for(int t = s + 1; t < n; t ++){
                int g = gcd(nums, s, t);
                if(g == 1) min_len = min(min_len, t - s + 1);
            }
        return min_len - 1 + n - 1;
    }

private:
    int gcd(vector<int>& nums, int s, int t){
        int g = nums[s];
        for(int i = s + 1; i <= t; i ++) g = gcd(g, nums[i]);
        return g;
    }

    template<typename T>
    T gcd(T a, T b){
        if(a < b) swap(a, b);
        while(b){
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
    }
};


int main() {

    vector<int> nums1 = {2, 6, 3, 4};
    cout << Solution().minOperations(nums1) << '\n';
    // 4

    vector<int> nums2 = {2, 10, 6, 14};
    cout << Solution().minOperations(nums2) << '\n';
    // -1

    vector<int> nums3 = {6, 10, 15};
    cout << Solution().minOperations(nums3) << '\n';
    // 4

    return 0;
}
