/// Source : https://leetcode.com/problems/minimum-absolute-difference-queries/
/// Author : liuyubobobo
/// Time   : 2021-06-19

#include <iostream>
#include <vector>

using namespace std;


/// Presum
/// Time Complexity: O(max(nums) * (n + q))
/// Space Complexity: O(max(nums) * n)
class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {

        int n = nums.size();

        int maxv = *max_element(nums.begin(), nums.end());
        vector<vector<int>> presum(maxv + 1, vector<int>(n + 1, 0));

        for(int v = 1; v <= maxv; v ++){
            for(int i = 0; i < nums.size(); i ++)
                presum[v][i + 1] = presum[v][i] + (nums[i] == v);
        }

        vector<int> res(queries.size(), -1);
        for(int i = 0; i < queries.size(); i ++){
            int l = queries[i][0], r = queries[i][1];

            int pre = -1, tres = INT_MAX;
            for(int v = 1; v <= maxv; v ++)
                if(presum[v][r + 1] - presum[v][l]){
                    if(pre != -1) tres = min(tres, v - pre);
                    pre = v;
                }
            res[i] = tres == INT_MAX ? -1 : tres;
        }
        return res;
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << " "; cout << endl;
}

int main() {

    vector<int> nums1 = {1, 3, 4, 8};
    vector<vector<int>> queries1 = {{0, 1}, {1, 2}, {2, 3}, {0, 3}};
    print_vec(Solution().minDifference(nums1, queries1));
    // 2 1 4 1

    vector<int> nums2 = {4,5,2,2,7,10};
    vector<vector<int>> queries2 = {{2, 3}, {0, 2}, {0, 5}, {3, 5}};
    print_vec(Solution().minDifference(nums2, queries2));
    // -1 1 1 3

    return 0;
}
