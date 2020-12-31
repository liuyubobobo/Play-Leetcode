/// Source : https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/
/// Author : liuyubobobo
/// Time   : 2017-10-22

#include <iostream>

using namespace std;

/// Memory Search
/// calculate the minimum delete ASCII sum for common sequence
///
/// Time Complexity: O(len(s1) * len(s2))
/// Space Complexity:  O(len(s1) * len(s2))
class Solution {

private:
    int dp[1001][1001];

public:
    int minimumDeleteSum(string s1, string s2) {

        for(int i = 0 ; i <= s1.size() ; i ++)
            for(int j = 0 ; j <= s2.size() ;j ++)
                dp[i][j] = -1;

        return minAscDelete(s1, 0, s2, 0);
    }

private:
    int minAscDelete(const string& s1, int i, const string& s2, int j){

        if(dp[i][j] != -1)
            return dp[i][j];

        if(i == s1.size() && j == s2.size())
            return dp[i][j] = 0;

        if(i == s1.size())
            return dp[i][j] = s2[j] + minAscDelete(s1, i, s2, j+1);

        if(j == s2.size())
            return dp[i][j] = s1[i] + minAscDelete(s1, i+1, s2, j);

        int res = min(s1[i] + minAscDelete(s1, i+1, s2, j),
                      s2[j] + minAscDelete(s1, i, s2, j+1));

        if(s1[i] == s2[j])
            res = min(res, minAscDelete(s1, i+1, s2, j+1));

        return dp[i][j] = res;
    }
};

int main() {

    cout << Solution().minimumDeleteSum("sea", "eat") << endl;
    cout << Solution().minimumDeleteSum("delete", "leet") << endl;

    return 0;
}