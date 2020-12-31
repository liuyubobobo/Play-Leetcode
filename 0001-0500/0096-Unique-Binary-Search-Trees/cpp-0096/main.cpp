/// Source : https://leetcode.com/problems/unique-binary-search-trees/description/
/// Author : liuyubobobo
/// Time   : 2018-09-10

#include <iostream>
#include <vector>

using namespace std;


/// Memory Search
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

public:
    int numTrees(int n) {

        vector<int> dp(n + 1, -1);
        return numTrees(n, dp);
    }

private:
    int numTrees(int n, vector<int>& dp){

        if(n <= 1)
            return 1;

        if(dp[n] != -1)
            return dp[n];

        int res = 0;
        for(int i = 1; i <= n; i ++)
            res += numTrees(i - 1, dp) * numTrees(n - i, dp);
        return dp[n] = res;
    }
};


int main() {

    cout << Solution().numTrees(3) << endl;

    return 0;
}