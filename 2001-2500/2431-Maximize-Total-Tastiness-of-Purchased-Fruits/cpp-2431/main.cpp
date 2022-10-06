/// Source : https://leetcode.com/problems/maximize-total-tastiness-of-purchased-fruits/
/// Author : liuyubobobo
/// Time   : 2022-10-06

#include <iostream>
#include <vector>

using namespace std;


/// Memoization
/// Time Complexity: O(n * maxAmount * maxCoupons)
/// Space Complexity: O(n * maxAmount * maxCoupons)
class Solution {
public:
    int maxTastiness(vector<int>& price, vector<int>& tastiness, int maxAmount, int maxCoupons) {

        int n = price.size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(maxAmount + 1, vector<int>(maxCoupons + 1, -1)));
        return dfs(price, tastiness, n - 1, maxAmount, maxCoupons, dp);
    }

private:
    int dfs(const vector<int>& price, const vector<int>& tastiness,
            int index, int amount, int coupons, vector<vector<vector<int>>>& dp){

        if(index == -1) return 0;
        if(dp[index][amount][coupons] != -1) return dp[index][amount][coupons];

        int res = dfs(price, tastiness, index - 1, amount, coupons, dp);
        if(price[index] <= amount)
            res = max(res, tastiness[index] + dfs(price, tastiness, index - 1, amount - price[index], coupons, dp));
        if(coupons && price[index] / 2 <= amount)
            res = max(res, tastiness[index] + dfs(price, tastiness, index - 1, amount - price[index] / 2, coupons - 1, dp));
        return dp[index][amount][coupons] = res;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
