/// Source : https://leetcode-cn.com/contest/cmbchina-2022spring/problems/OK3hsO/
/// Author : liuyubobobo
/// Time   : 2022-04-13

#include <iostream>
#include <vector>

using namespace std;


/// Memoization
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int goShopping(vector<int>& priceA, vector<int>& priceB) {

        int n = priceA.size();
        vector<pair<long long, long long>> price(n);
        for(int i = 0; i < n; i ++)
            price[i] = {priceB[i] * 10ll, priceA[i] * 10ll};

        sort(price.begin(), price.end(), greater<pair<long long, long long>>());

        // 2 * 4 * 3 * n
        // 2: 0 - no use a discount; 1 - use a discount
        // 4: last a number
        // 3: last b number
        vector<vector<long long>> dp(24, vector<long long>(n, -1));
        return min(dfs(n, price, 0, 0, 0, 0, dp), dfs(n, price, 1, 0, 0, 0, dp)) / 10;
    }

private:
    long long dfs(int n, const vector<pair<long long, long long>>& price,
                  int use_a, int last_a, int last_b, int index,
                  vector<vector<long long>>& dp){

        if(index == n){
            if(!use_a) return last_a == 3 ? LONG_LONG_MAX / 2 : 0;
            return last_a < 3 ? LONG_LONG_MAX / 2 : 0;
        }

        if(!use_a && last_a == 3) return LONG_LONG_MAX / 2;

        int state1 = use_a * 12 + last_a * 3 + last_b;
        if( dp[state1][index] != -1) return dp[state1][index];

        long long res = (last_b == 2 ? 0 : price[index].first) + dfs(n, price, use_a, last_a, (last_b + 1) % 3, index + 1, dp);
        if(use_a)
            res = min(res, price[index].second / 10 * 7 + dfs(n, price, use_a, min(last_a + 1, 3), last_b, index + 1, dp));
        else
            res = min(res, price[index].second + dfs(n, price, use_a, min(last_a + 1, 3), last_b, index + 1, dp));
        return dp[state1][index] = res;
    }
};

int main() {

    vector<int> price1A = {1, 2, 5}, price1B = {2, 2, 2};
    cout << Solution().goShopping(price1A, price1B) << '\n';
    // 4

    vector<int> price2A = {1, 6, 1}, price2B = {2, 2, 6};
    cout << Solution().goShopping(price2A, price2B) << '\n';
    // 4

    vector<int> price3A = {3, 13, 5, 12}, price3B = {28, 12, 20, 7};
    cout << Solution().goShopping(price3A, price3B) << '\n';
    // 21

    return 0;
}
