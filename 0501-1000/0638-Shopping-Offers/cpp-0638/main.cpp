/// Source : https://leetcode.com/problems/shopping-offers/
/// Author : liuyubobobo
/// Time   : 2021-10-23

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Backpack
/// Memoization
/// Time Complexity: O((price[i] ^ n) * m)
/// Space Complexity: O(price[i] ^ n)
class Solution {
public:
    int shoppingOffers(vector<int>& prices, vector<vector<int>>& specials, vector<int>& needs) {

        int n = prices.size();
        int m = specials.size();
        map<vector<int>, int> dp;
        return dfs(n, needs, m, specials, prices, dp);
    }

private:
    int dfs(int n, const vector<int>& need, int m, const vector<vector<int>>& specials,
            const vector<int>& prices, map<vector<int>, int>& dp){

        if(dp.count(need)) return dp[need];

        int res = 0;
        for(int i = 0; i < n; i ++) res += need[i] * prices[i];

        for(int i = 0; i < m; i ++)
            if(less_or_equals(n, specials[i], need))
                res = min(res, specials[i].back() + dfs(n, minus(n, need, specials[i]), m, specials, prices, dp));

        return dp[need] = res;
    }

    bool less_or_equals(int n, const vector<int>& a, const vector<int>& b){
        for(int i = 0; i < n; i ++)
            if(a[i] > b[i]) return false;
        return true;
    }

    vector<int> minus(int n, const vector<int>& a, const vector<int>& b){
        vector<int> res(n);
        for(int i = 0; i < n; i ++) res[i] = a[i] - b[i];
        return res;
    }
};


int main() {

    vector<int> prices1 = {2, 5};
    vector<vector<int>> specials1 = {{3, 0, 5}, {1, 2, 10}};
    vector<int> needs1= {3, 2};
    cout << Solution().shoppingOffers(prices1, specials1, needs1) << endl;
    // 14

    vector<int> prices2 = {2, 3, 4};
    vector<vector<int>> specials2 = {{1, 1, 0, 4}, {2, 2, 1, 9}};
    vector<int> needs2 = {1, 2, 1};
    cout << Solution().shoppingOffers(prices2, specials2, needs2) << endl;
    // 11

    vector<int> prices3 = {0, 0, 0};
    vector<vector<int>> specials3 = {{1, 1, 0, 4}, {2, 2, 1, 9}};
    vector<int> needs3 = {1, 1, 1};
    cout << Solution().shoppingOffers(prices3, specials3, needs3) << endl;
    // 0

    return 0;
}
