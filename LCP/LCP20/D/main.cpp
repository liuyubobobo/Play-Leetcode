/// Source : https://leetcode-cn.com/problems/meChtZ/
/// Author : liuyubobobo
/// Time   : 2020-09-12

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;


/// Memory Search
/// Time Complexity: O(target)
/// Space Complexity: O(target)
class Solution {

private:
    long long MOD = 1e9 + 7;

public:
    int busRapidTransit(int target, int inc, int dec, vector<int>& jump, vector<int>& cost) {

        unordered_map<int, long long> dp;
        return dfs(target, inc, dec, jump, cost, dp) % MOD;
    }

private:
    long long dfs(int target, int inc, int dec, const vector<int>& jump, const vector<int>& cost,
                  unordered_map<int, long long>& dp){

//        cout << target << endl;
        if(dp.count(target)) return dp[target];

        if(target == 0) return dp[target] = 0ll;
        if(target == 1) return dp[target] = (long long)inc;

        long long res = (long long)target * inc;
        for(int i = 0; i < jump.size(); i ++){
            res = min(res, dfs(target / jump[i], inc, dec, jump, cost, dp) + (long long)cost[i] + (long long)(target % jump[i]) * inc);
            if(target > 1 && target % jump[i])
                res = min(res, dfs(target / jump[i] + 1, inc, dec, jump, cost, dp) + (long long)cost[i] + ((long long)(target / jump[i] + 1) * jump[i] - target) * dec);
        }
        return dp[target] = res;
    }
};


int main() {

    vector<int> jump1 = {6}, cost1 = {10};
    cout << Solution().busRapidTransit(31, 5, 3, jump1, cost1) << endl;
    // 33

    vector<int> jump2 = {3,6,8,11,5,10,4}, cost2 = {4,7,6,3,7,6,4};
    cout << Solution().busRapidTransit(612, 4, 5, jump2, cost2) << endl;
    // 26

    vector<int> jump3 = {2}, cost3 = {1000000};
    cout << Solution().busRapidTransit(1000000000, 1, 1, jump3, cost3) << endl;
    // 10953125

    return 0;
}
