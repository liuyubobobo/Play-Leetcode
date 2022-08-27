/// Source : https://leetcode.cn/submissions/detail/355567783/
/// Author : liuyubobobo
/// Time   : 2022-08-27

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cassert>

using namespace std;


/// Memoization
/// The state transfer is super clever
/// Time Complexity: O(?)
/// Space Complexity: O(?)
class Solution {
public:
    double chipGame(vector<int>& nums, int kind) {

        while(nums.size() < kind) nums.push_back(0);

        sort(nums.begin(), nums.end());

        map<vector<int>, double> dp;
        dp[nums] = 0;

        vector<int> cur(kind, 0);
        double res = dfs(kind, cur, nums, dp);
        return res;
    }

private:
    double dfs(int n, vector<int>& cur, const vector<int>& target,
               map<vector<int>, double>& dp){

        if(dp.count(cur)) return dp[cur];

        double res = 1;
        int choice = 0;
        for(int start = 0, i = 1; i <= n; i ++)
            if(i == n || cur[i] != cur[start]){

                int index = i - 1;
                if(cur[index] == target[index]){
                    start = i;
                    continue;
                }

                int len = i - start;
                choice += len;
                double p = (double)len / n;

                cur[index] ++;
                res += p * dfs(n, cur, target, dp);
                cur[index] --;

                start = i;
            }

        assert(choice <= n);
        res /= (1.0 - (double)(n - choice) / n);
        return dp[cur] = res;
    }
};


int main() {

//    vector<int> nums1 = {1, 1};
//    cout << Solution().chipGame(nums1, 2) << '\n';
//    // 3

    vector<int> nums2 = {1, 2};
    cout << Solution().chipGame(nums2, 4) << '\n';
    // 3.833333

    return 0;
}
