/// Source : https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations/description/
/// Author : liuyubobobo
/// Time   : 2023-03-27

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// Using Hash Table
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {

        vector<int> f(2e5, 0);
        for(int e: nums){
            if(e >= 0){
                int k = e / value; f[e - k * value] ++;
            }
            else{
                int k = (-e) / value + !!((-e) % value); f[e + k * value] ++;
            }
        }

        for(int res = 0;; res ++){
            int k = res / value, t = res - k * value;
            if(f[t]) f[t] --;
            else return res;
        }
        return -1;
    }
};


int main() {

    vector<int> nums1 = {1, -10, 7, 13, 6, 8};
    cout << Solution().findSmallestInteger(nums1, 5) << '\n';
    // 4

    vector<int> nums2 = {1, -10, 7, 13, 6, 8};
    cout << Solution().findSmallestInteger(nums2, 7) << '\n';
    // 2

    return 0;
}
