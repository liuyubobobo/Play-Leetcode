/// Source : https://leetcode.com/problems/allocate-mailboxes/
/// Author : liuyubobobo
/// Time   : 2020-06-13

#include <iostream>
#include <vector>

using namespace std;


/// Memory Search
/// Time Complexity: O(k*n^2)
/// Space Complexity: O(k*n)
class Solution {

private:
    int n;

public:
    int minDistance(vector<int>& houses, int k) {

        n = houses.size();
        sort(houses.begin(), houses.end());

        vector<vector<int>> dis(n, vector<int>(n));
        for(int i = 0; i < n; i ++)
            for(int j = i; j < n; j ++)
                dis[i][j] = getdis(houses, i, j);

        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return dfs(houses, 0, k, dis, dp);
    }

private:
    int dfs(const vector<int>& houses, int index, int left,
            const vector<vector<int>>& dis, vector<vector<int>>& dp){

        if(left == -1) return INT_MAX;
        if(index == n) return left == 0 ? 0 : INT_MAX;
        if(dp[index][left] != -1) return dp[index][left];

        int res = INT_MAX;
        for(int i = index; i < n; i ++){
            int tres = dfs(houses, i + 1, left - 1, dis, dp);
            if(tres != INT_MAX) res = min(res, dis[index][i] + tres);
        }
        return dp[index][left] = res;
    }

    int getdis(const vector<int>& houses, int start, int end){

        int mid = (start + end) / 2;
        int res = 0;
        for(int i = start; i <= end; i ++) res += abs(houses[i] - houses[mid]);
        return res;
    }
};


int main() {

    vector<int> houses1 = {1,4,8,10,20};
    cout << Solution().minDistance(houses1, 3) << endl;
    // 5

    vector<int> houses2 = {2,3,5,12,18};
    cout << Solution().minDistance(houses2, 2) << endl;
    // 9

    vector<int> houses3 = {7,4,6,1};
    cout << Solution().minDistance(houses3, 1) << endl;
    // 8

    vector<int> houses4 = {3,6,14,10};
    cout << Solution().minDistance(houses4, 4) << endl;
    // 0

    return 0;
}
