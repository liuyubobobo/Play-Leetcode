/// Source : https://leetcode.com/problems/minimum-cost-to-merge-stones/
/// Author : liuyubobobo
/// Time   : 2019-03-04

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Memory Search
/// Time Complexity: O(n^3 * K)
/// Space Complexity: O(n^3)
class Solution {

public:
    int mergeStones(vector<int>& stones, int K) {

        int n = stones.size();
        if((n - 1) % (K - 1)) return -1;

        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(K + 1, -1)));
        return dfs(stones, 0, n - 1, 1, K, dp);
    }

    int dfs(const vector<int>& stones, int l, int r, int pile, int K,
            vector<vector<vector<int>>>& dp){

        if(dp[l][r][pile] != -1) return dp[l][r][pile];

        if(l == r)
            return dp[l][r][pile] = (pile == 1 ? 0 : INT_MAX);

        if(pile == 1) {
            int tres = dfs(stones, l, r, K, K, dp);
            return dp[l][r][pile] = tres == INT_MAX ? tres :
                                    tres + accumulate(stones.begin() + l, stones.begin() + (r + 1), 0);
        }

        int res = INT_MAX;
        for(int i = l; i < r; i ++){
            int tres1 = dfs(stones, l, i, 1, K, dp),
                tres2 = dfs(stones, i + 1, r, pile - 1, K, dp);
            if(tres1 != INT_MAX && tres2 != INT_MAX)
                res = min(res, tres1 + tres2);
        }
        return dp[l][r][pile] = res;
    }
};


int main() {

    vector<int> stones1 = {3,2,4,1};
    cout << Solution().mergeStones(stones1, 2) << endl;
    // 20

    vector<int> stones2 = {3,2,4,1};
    cout << Solution().mergeStones(stones2, 3) << endl;
    // -1

    vector<int> stones3 = {3,5,1,2,6};
    cout << Solution().mergeStones(stones3, 3) << endl;
    // 25

    vector<int> stones4 = {1};
    cout << Solution().mergeStones(stones4, 2) << endl;
    // 0

    vector<int> stones5 = {69,39,79,78,16,6,36,97,79,27,14,31,4};
    cout << Solution().mergeStones(stones5, 2) << endl;
    // 1957

    vector<int> stones6 = {95,54,31,48,44,96,99,20,51,54,18,85,25,84,91,48,40,72,22};
    cout << Solution().mergeStones(stones6, 2) << endl;
    // 4517

    return 0;
}