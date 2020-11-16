/// Source : https://leetcode.com/problems/distribute-repeating-integers/
/// Author : liuyubobobo
/// Time   : 2020-11-16

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;


/// Memory Search
/// Time Complexity: O(n * (2^m) * (2^m))
/// Space Complexity: O(n * (2^m))
class Solution {
public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {

        unordered_map<int, int> f;
        for(int e: nums) f[e] ++;

        vector<int> v;
        for(const pair<int, int>& p: f) v.push_back(p.second);

        vector<int> sum(1 << quantity.size());
        for(int state = 0; state < sum.size(); state ++)
            sum[state] = get_sum(quantity, state);

        vector<vector<int>> dp(v.size(), vector<int>(1 << quantity.size(), -1));
        return dfs(v, sum, 0, 0, dp);
    }

private:
    bool dfs(const vector<int>& v, const vector<int>& sum, int index, int state,
             vector<vector<int>>& dp){

        if(state == sum.size() - 1) return true;
        if(index == v.size()) return false;

        if(dp[index][state] != -1) return dp[index][state];

        for(int i = 0; i < sum.size(); i ++)
            if((i & state) == 0 && v[index] >= sum[i] && dfs(v, sum, index + 1, state | i, dp))
                return dp[index][state] = true;

        return dp[index][state] = false;
    }

    int get_sum(const vector<int>& q, int state){

        int res = 0, index = 0;
        while(state){
            if(state % 2) res += q[index];
            index ++;
            state /= 2;
        }
        return res;
    }
};


int main() {

    vector<int> nums1 = {1, 2, 3, 4}, q1 = {2};
    cout << Solution().canDistribute(nums1, q1) << endl;
    // 0

    vector<int> nums2 = {1, 2, 3, 3}, q2 = {2};
    cout << Solution().canDistribute(nums2, q2) << endl;
    // 1

    vector<int> nums3 = {1, 1, 2, 2}, q3 = {2, 2};
    cout << Solution().canDistribute(nums3, q3) << endl;
    // 1

    vector<int> nums4 = {1, 1, 2, 3}, q4 = {2, 2};
    cout << Solution().canDistribute(nums4, q4) << endl;
    // 0

    vector<int> nums5 = {1, 1, 1, 1, 1}, q5 = {2, 3};
    cout << Solution().canDistribute(nums5, q5) << endl;
    // 1

    return 0;
}
