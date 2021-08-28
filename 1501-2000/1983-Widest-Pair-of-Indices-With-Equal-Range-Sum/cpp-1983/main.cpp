/// Source : https://leetcode.com/problems/widest-pair-of-indices-with-equal-range-sum/
/// Author : liuyubobobo
/// Time   : 2021-08-27

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Hash Table
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int widestPairOfIndices(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        vector<int> data(n);
        for(int i = 0; i < n; i ++)
            data[i] = nums1[i] - nums2[i];

        unordered_map<int, int> map;
        map[0] = -1;
        int res = 0, cur = 0;
        for(int i = 0; i < n; i ++){
            cur += data[i];
            if(map.count(cur))
                res = max(res, i - map[cur]);
            else
                map[cur] = i;
        }
        return res;
    }
};


int main() {

    vector<int> nums11 = {1, 1, 0, 1}, nums12 = {0, 1, 1, 0};
    cout << Solution().widestPairOfIndices(nums11, nums12) << endl;
    // 3

    vector<int> nums21 = {0, 1, 1}, nums22 = {1, 0, 1};
    cout << Solution().widestPairOfIndices(nums21, nums22) << endl;
    // 3

    return 0;
}
