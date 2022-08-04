/// Source : https://leetcode.com/problems/minimum-costs-using-the-train-line/
/// Author : liuyubobobo
/// Time   : 2022-08-03

#include <iostream>
#include <vector>

using namespace std;


/// DP
/// Time Compelxity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<long long> minimumCosts(vector<int>& regular, vector<int>& express, int expressCost) {

        int n = regular.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));
        dp[0][1] = expressCost;

        vector<long long> res(n);
        for(int i = 1; i <= n; i ++){
            dp[i][0] = min(dp[i - 1][0] + regular[i - 1], dp[i - 1][1] + express[i - 1]);
            dp[i][1] = min(dp[i - 1][0] + regular[i - 1] + expressCost, dp[i - 1][1] + express[i - 1]);
            res[i - 1] = min(dp[i][0], dp[i][1]);
        }
        return res;
    }
};


void print_vec(const vector<long long>& res){
    for(long long e: res) cout << e << ' '; cout << '\n';
}

int main() {

    vector<int> regular1 = {1, 6, 9, 5}, express1 = {5, 2, 3, 10};
    print_vec(Solution().minimumCosts(regular1, express1, 8));

    return 0;
}
