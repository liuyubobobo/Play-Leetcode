/// Source : https://leetcode.com/problems/optimal-division/
/// Author : liuyubobobo
/// Time   : 2022-02-27

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/// DP
/// Time Complexity: O(n^3)
/// Space Complexity: O(n^2)
class Solution {

public:
    string optimalDivision(vector<int>& nums) {

        int n = nums.size();

        vector<vector<long double>> dp_max(n, vector<long double>(n, 0.0));
        vector<vector<int>> dp_max_sz(n, vector<int>(n, 1));
        vector<vector<long double>> dp_min(n, vector<long double>(n, 0.0));
        vector<vector<int>> dp_min_sz(n, vector<int>(n, 1));
        for(int i = 0; i < n; i ++)
            dp_max[i][i] = dp_min[i][i] = nums[i];
        for(int i = 0; i + 1 < n; i ++)
            dp_max[i][i + 1] = dp_min[i][i + 1] = (long double)nums[i] / nums[i + 1];
        for(int sz = 2; sz <= n; sz ++)
            for(int i = 0; i + sz <= n; i ++){
                // calc dp[i][i + sz - 1]
                dp_max[i][i + sz - 1] = dp_max[i][i] / dp_min[i + 1][i + sz - 1];
                dp_min[i][i + sz - 1] = dp_min[i][i] / dp_max[i + 1][i + sz - 1];
                for(int sz1 = 2; sz1 < sz; sz1 ++){
                    if(dp_max[i][i + sz1 - 1] / dp_min[i + sz1][i + sz - 1] > dp_max[i][i + sz - 1])
                        dp_max[i][i + sz - 1] = dp_max[i][i + sz1 - 1] / dp_min[i + sz1][i + sz - 1], dp_max_sz[i][i + sz - 1] = sz1;
                    if(dp_min[i][i + sz1 - 1] / dp_max[i + sz1][i + sz - 1] < dp_min[i][i + sz - 1])
                        dp_min[i][i + sz - 1] = dp_min[i][i + sz1 - 1] / dp_max[i + sz1][i + sz - 1], dp_min_sz[i][i + sz - 1] = sz1;
                }
            }

        return get_string(nums, 0, n - 1, "max", dp_max_sz, dp_min_sz);
    }

private:
    string get_string(const vector<int>& nums, int l, int r, const string& type,
                      const vector<vector<int>>& dp_max_sz,
                      const vector<vector<int>>& dp_min_sz){

        if(l == r) return to_string(nums[l]);
        if(l + 1 == r) return to_string(nums[l]) + "/" + to_string(nums[r]);

        if(type == "max"){
            int sz = r - l + 1, sz1 = dp_max_sz[l][r];
            string left_str = get_string(nums, l, l + sz1 - 1, "max", dp_max_sz, dp_min_sz);
            string right_str = get_string(nums, l + sz1, l + sz - 1, "min", dp_max_sz, dp_min_sz);
            if(l + sz1 == l + sz - 1) return left_str + "/" + right_str;
            return left_str + "/(" + right_str + ")";
        }
        else{
            assert(type == "min");

            int sz = r - l + 1, sz1 = dp_min_sz[l][r];
            string left_str = get_string(nums, l, l + sz1 - 1, "min", dp_max_sz, dp_min_sz);
            string right_str = get_string(nums, l + sz1, l + sz - 1, "max", dp_max_sz, dp_min_sz);
            if(l + sz1 == l + sz - 1) return left_str + "/" + right_str;
            return left_str + "/(" + right_str + ")";
        }
    }
};


int main() {

    vector<int> nums1 = {1000, 100, 10, 2};
    cout << Solution().optimalDivision(nums1) << endl;
    // 1000/(100/10/2)

    vector<int> nums2 = {2, 3, 4};
    cout << Solution().optimalDivision(nums2) << endl;
    // 2/(3/4)

    vector<int> nums3 = {2};
    cout << Solution().optimalDivision(nums3) << endl;
    // 2

    return 0;
}
