/// Source : https://leetcode.com/problems/find-the-punishment-number-of-an-integer/description/
/// Author : liuyubobobo
/// Time   : 2023-05-21

#include <iostream>
#include <vector>

using namespace std;


/// Memoization
/// Time Complexity: O(n * n * logn)
/// Space Complexity: O(nlogn)
class Solution {
public:
    int punishmentNumber(int n) {

        int res = 0;
        for(int i = 1; i <= n; i ++){
            int num = i * i;
            if(check(num, i)) res += num;
        }
        return res;
    }

private:
    bool check(int num, int sum){
        string num_str = to_string(num);
        vector<vector<int>> dp(num_str.size(), vector<int>(sum + 1, -1));
        return dfs(num_str, 0, sum, dp);
    }

    int dfs(const string& s, int index, int sum, vector<vector<int>>& dp){

        if(index == s.size()) return sum == 0;
        if(sum < 0) return 0;
        if(dp[index][sum] != -1) return dp[index][sum];

        int cur = 0;
        for(int i = index; i < s.size(); i ++){
            cur = cur * 10 + (s[i] - '0');
            if(dfs(s, i + 1, sum - cur, dp)) return dp[index][sum] = 1;
        }
        return dp[index][sum] = 0;
    }
};

int main() {

    return 0;
}
