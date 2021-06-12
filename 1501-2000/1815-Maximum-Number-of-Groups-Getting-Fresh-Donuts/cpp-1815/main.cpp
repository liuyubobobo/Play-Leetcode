/// Source : https://leetcode.com/problems/maximum-number-of-groups-getting-fresh-donuts/
/// Author : liuyubobobo
/// Time   : 2020-06-11

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


/// Memory Search - vector as key
/// Time Complexity: O(2^n)
/// Space Complexity: O(2^n)
class Solution {
public:
    int maxHappyGroups(int batchSize, vector<int>& groups) {

        vector<int> f(batchSize);
        for(int e: groups) f[e % batchSize] ++;

        int res = f[0];
        f[0] = 0;

        map<vector<int>, int> dp;
        res += dfs(f, batchSize, dp);
        return res;
    }

private:
    int dfs(vector<int>& f, int k, map<vector<int>, int>& dp){

        auto iter = dp.find(f);
        if(iter != dp.end()) return iter->second;

        int pre = f[0];
        int res = 0;
        for(int i = 1; i < f.size(); i ++)
            if(f[i]){
                f[i] --;
                f[0] = (pre + i) % k;
                res = max(res, (pre == 0) + dfs(f, k, dp));
                f[0] = pre;
                f[i] ++;
            }
        return dp[f] = res;
    }
};


int main() {

    vector<int> groups1 = {1, 2, 3, 4, 5, 6};
    cout << Solution().maxHappyGroups(3, groups1) << endl;
    // 4

    vector<int> groups2 = {1, 3, 2, 5, 2, 2, 1, 6};
    cout << Solution().maxHappyGroups(4, groups2) << endl;
    // 4

    vector<int> groups3 = {909925048,861425549,820096754,67760437,273878288,126614243,531969375,817077202,482637353,507069465,699642631,407608742,846885254,225437260,100780964,523832097,30437867,959191866,897395949};
    cout << Solution().maxHappyGroups(1, groups3) << endl;
    // 19

    return 0;
}