/// Source : https://leetcode.com/problems/stone-game-iii/
/// Author : liuyubobobo
/// Time   : 2020-04-04

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Memory Search
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {

        int n = stoneValue.size();

        vector<int> postsum(n + 1, 0);
        for(int i = n - 1; i >= 0; i --) postsum[i] = postsum[i + 1] + stoneValue[i];

        vector<vector<int>> dp(2, vector<int>(stoneValue.size(), INT_MIN));
        int x = dfs(stoneValue, 0, 0, dp, postsum);
//        cout << x << endl;
        if(x > postsum[0] - x) return "Alice";
        else if(x < postsum[0] - x) return "Bob";
        return "Tie";
    }

private:
    int dfs(const vector<int>& values, int index, int player,
            vector<vector<int>>& dp, const vector<int>& postsum){

        if(index >= values.size()) return 0;
        if(dp[player][index] != INT_MIN) return dp[player][index];

        int sum = 0, res = INT_MIN;
        for(int i = 0; i < 3 && index + i < values.size(); i ++){
            sum += values[index + i];
            int tres = sum + postsum[index + i + 1] - dfs(values, index + i + 1, 1 - player, dp, postsum);
//            cout << "playe = " << player << " ; index = " << index << " : " << tres << endl;
            res = max(res, tres);
        }
        return dp[player][index] = res;
    }
};


int main() {

    vector<int> values1 = {1, 2, 3, 7};
    cout << Solution().stoneGameIII(values1) << endl;
    // Bob

    vector<int> values2 = {1, 2, 3, -9};
    cout << Solution().stoneGameIII(values2) << endl;
    // Alice

    vector<int> values3 = {1, 2, 3, 6};
    cout << Solution().stoneGameIII(values3) << endl;
    // Tie

    vector<int> values4 = {1,2,3,-1,-2,-3,7};
    cout << Solution().stoneGameIII(values4) << endl;
    // Alice

    vector<int> values5 = {-1, -2, -3};
    cout << Solution().stoneGameIII(values5) << endl;
    // Tie

    return 0;
}
