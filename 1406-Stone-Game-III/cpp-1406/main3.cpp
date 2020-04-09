/// Source : https://leetcode.com/problems/stone-game-iii/
/// Author : liuyubobobo
/// Time   : 2020-04-08

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// One dimensional DP without postsum
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {

        int n = stoneValue.size();
        vector<int> dp(n + 1, INT_MIN);
        dp[n] = 0;
        dp[n - 1] = stoneValue[n - 1];

        for(int start = n - 2; start >= 0; start --){
            int sum = 0;
            for(int i = 0; i < 3 && start + i < n; i ++){
                sum += stoneValue[start + i];
                dp[start] = max(dp[start], sum - dp[start + i + 1]);
            }
        }

        if(dp[0] > 0) return "Alice";
        else if(dp[0] < 0) return "Bob";
        return "Tie";
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
