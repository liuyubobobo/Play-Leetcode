/// Source : https://leetcode.com/problems/minimum-operations-to-reduce-an-integer-to-0/description/
/// Author : liuyubobobo
/// Time   : 2023-02-20

#include <iostream>
#include <vector>

using namespace std;


/// Memoization
/// Time Complexity: O(logn)
/// Space Complexity: O(logn)
class Solution {
public:
    int minOperations(int n) {

        vector<int> v;
        while(n) v.push_back(n & 1), n >>= 1;

        vector<vector<int>> dp(v.size(), vector<int>(2, 0));
        return dfs(v, 0, 0, dp);
    }

private:
    int dfs(const vector<int>& v, int index, int last, vector<vector<int>>& dp){

        if(index == v.size()) return last == 1 ? 2 : 0;

        if(dp[index][last] != 0) return dp[index][last];

        int res = INT_MAX;
        if(last == 0){
            if(v[index] == 0) res = min(res, dfs(v, index + 1, 0, dp));
            else{
                res = min(res, dfs(v, index + 1, 1, dp));
                res = min(res, dfs(v, index + 1, 0, dp) + 1);
            }
        }
        else{
            if(v[index] == 0){
                res = min(res, dfs(v, index + 1, 0, dp) + 2);
                res = min(res, dfs(v, index + 1, 1, dp) + 1);
            }
            else res = min(res, dfs(v, index + 1, 1, dp));
        }
        return dp[index][last] = res;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
