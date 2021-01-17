/// Source : https://leetcode.com/problems/tuple-with-same-product/
/// Author : liuyubobobo
/// Time   : 2021-01-17

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// HashMap
/// Time Complexity: O(n^2)
/// Space Complexity: O(n^2)
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {

        unordered_map<int, int> f;
        for(int i = 0; i < nums.size(); i ++)
            for(int j = i + 1; j < nums.size(); j ++)
                f[nums[i] * nums[j]] ++;

        int res = 0;
        for(const pair<int, int>& p: f)
            res += 4 * p.second * (p.second - 1);
        return res;
    }
};


int main() {

    vector<int> nums1 = {2, 3, 4, 6};
    cout << Solution().tupleSameProduct(nums1) << endl;
    // 8

    vector<int> nums2 = {1, 2, 4, 5, 10};
    cout << Solution().tupleSameProduct(nums2) << endl;
    // 16

    vector<int> nums3 = {2, 3, 4, 6, 8, 12};
    cout << Solution().tupleSameProduct(nums3) << endl;
    // 40

    vector<int> nums4 = {2, 3, 5, 7};
    cout << Solution().tupleSameProduct(nums4) << endl;
    // 0

    return 0;
}
