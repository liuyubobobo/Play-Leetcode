/// Source : https://leetcode.com/problems/jump-game-v/
/// Author : liuyubobobo
/// Time   : 2019-02-01

#include <iostream>
#include <vector>

using namespace std;


/// Memorized Search
/// Time Complexity: O(n * d)
/// Space Complexity: O(n)
class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {

        vector<int> dp(arr.size(), -1);
        for(int i = 0; i < arr.size(); i ++)
            dfs(arr, d, i, dp);
//        for(int e: dp) cout << e << " "; cout << endl;
        return *max_element(dp.begin(), dp.end());
    }

private:
    int dfs(const vector<int>& arr, int d, int pos, vector<int>& dp){

        if(dp[pos] != -1) return dp[pos];

        int res = 1;
        for(int i = pos - 1; i >= 0 && i >= pos - d; i --)
            if(arr[i] < arr[pos])
                res = max(res, 1 + dfs(arr, d, i, dp));
            else break;

        for(int i = pos + 1; i < arr.size() && i <= pos + d; i ++)
            if(arr[i] < arr[pos])
                res = max(res, 1 + dfs(arr, d, i, dp));
            else break;

        return dp[pos] = res;
    }
};


int main() {

    vector<int> arr1 = {6,4,14,6,8,13,9,7,10,6,12};
    cout << Solution().maxJumps(arr1, 2) << endl;
    // 4

    return 0;
}
