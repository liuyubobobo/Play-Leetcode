/// Source : https://leetcode.com/problems/minimum-incompatibility/
/// Author : liuyubobobo
/// Time   : 2020-12-05

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// State Compression DP
/// Time Complexity: O(2^n * logn + 2^n * C(n, n / k))
/// Space Complexity: O(C(n, n / k))
class Solution {
public:
    int minimumIncompatibility(vector<int>& nums, int k) {

        int n = nums.size();
        unordered_map<int, int> table;

        int sz = n / k;
        for(int state = 1; state < (1 << n); state ++)
            if(ones(state) == sz){
                deal(table, nums, state);
            }

        vector<int> dp(1 << n, -1);
        int res = dfs(table, (1 << n) - 1, dp);
        return res == INT_MAX ? -1 : res;
    }

private:
    int dfs(const unordered_map<int, int>& table, int state,
            vector<int>& dp){

        if(state == 0) return 0;
        if(dp[state] != -1) return dp[state];

        int res = INT_MAX;
        for(const pair<int, int>& p: table)
            if((state & p.first) == p.first) {
                int t = dfs(table, state - p.first, dp);
                if(t != INT_MAX) res = min(res, p.second + t);
            }
        return dp[state] = res;
    }

    void deal(unordered_map<int, int>& table, const vector<int>& nums, int state){

        vector<int> v;
        int index = 0, x = state;
        while(x){
            if(x & 1) v.push_back(nums[index]);
            index ++;
            x >>= 1;
        }

        sort(v.begin(), v.end());
        for(int i = 1; i < v.size(); i ++)
            if(v[i - 1] == v[i]) return;

        table[state] = v.back() - v[0];
    }

    int ones(int x){
        int res = 0;
        while(x){
            x = x & (x - 1);
            res ++;
        }
        return res;
    }
};


int main() {

    vector<int> nums1 = {1, 2, 1, 4};
    cout << Solution().minimumIncompatibility(nums1, 2) << endl;
    // 4

    vector<int> nums2 = {6,3,8,1,3,1,2,2};
    cout << Solution().minimumIncompatibility(nums2, 4) << endl;
    // 6

    vector<int> nums3 = {5,3,3,6,3,3};
    cout << Solution().minimumIncompatibility(nums3, 3) << endl;
    // -1

    vector<int> nums4 = {1};
    cout << Solution().minimumIncompatibility(nums4, 1) << endl;
    // 0

    return 0;
}