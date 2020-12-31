/// Source : https://leetcode.com/problems/max-number-of-k-sum-pairs/
/// Author : liuyubobobo
/// Time   : 2020-12-05

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Using HashMap - Single Pass
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {

        unordered_map<int, int> f;

        int res = 0;
        for(int e: nums){
            if(f[k - e] > 0){
                res ++;
                f[k - e] --;
            }
            else f[e] ++;
        }
        return res;
    }
};


int main() {

    vector<int> nums1 = {1, 2, 3, 4};
    cout << Solution().maxOperations(nums1, 5) << endl;
    // 2

    vector<int> nums2 = {3,1,3,4,3};
    cout << Solution().maxOperations(nums2, 6) << endl;
    // 1

    return 0;
}