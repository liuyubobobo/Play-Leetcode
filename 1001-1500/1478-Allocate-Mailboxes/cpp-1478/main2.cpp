/// Source : https://leetcode.com/problems/allocate-mailboxes/
/// Author : liuyubobobo
/// Time   : 2020-06-13

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(k*n^2)
/// Space Complexity: O(k*n)
class Solution {

public:
    int minDistance(vector<int>& houses, int k) {

        int n = houses.size();
        sort(houses.begin(), houses.end());

        vector<vector<int>> dis(n, vector<int>(n));
        for(int i = 0; i < n; i ++)
            for(int j = i; j < n; j ++)
                dis[i][j] = getdis(houses, i, j);

        vector<vector<int>> dp(k + 1, vector<int>(n, INT_MAX));
        for(int i = 0; i < n; i ++)
            dp[1][i] = dis[0][i];

        for(int cnt = 2; cnt <= k; cnt ++)
            for(int end = cnt - 1; end < n; end ++)
                for(int start = end; start >= cnt - 1; start --)
                    if(dp[cnt - 1][start - 1] != INT_MAX)
                        dp[cnt][end] = min(dp[cnt][end], dis[start][end] + dp[cnt - 1][start - 1]);
        return dp[k][n - 1];
    }

private:
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

    vector<int> houses5 = {1,4,8,10,20};
    cout << Solution().minDistance(houses5, 3) << endl;
    // 5

    return 0;
}
