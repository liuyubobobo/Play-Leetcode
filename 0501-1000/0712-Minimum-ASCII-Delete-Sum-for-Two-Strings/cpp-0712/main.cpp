/// Source : https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/
/// Author : liuyubobobo
/// Time   : 2017-10-21

#include <iostream>
#include <string>

using namespace std;

/// Memory Search
/// calculate the max ASCII sum of common sequence
///
/// Time Complexity: O(len(s1) * len(s2))
/// Space Complexity:  O(len(s1) * len(s2))
class Solution {

private:
    int dp[1001][1001];

public:
    int minimumDeleteSum(string s1, string s2) {

        for(int i = 0 ; i < s1.size() ; i ++)
            for(int j = 0 ; j < s2.size() ;j ++)
                dp[i][j] = -1;

        int maxAsc = maxascLCS(s1, 0, s2, 0);

        int ascSum1 = ascSum(s1);
        int ascSum2 = ascSum(s2);

        return ascSum1 + ascSum2 - 2*maxAsc;
    }

private:
    int maxascLCS(const string& s1, int i, const string& s2, int j){

        if(i >= s1.size() || j >= s2.size())
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int res = 0;
        if(s1[i] == s2[j])
            res = max(res, (int)s1[i] + maxascLCS(s1, i+1, s2, j+1));

        res = max(res, maxascLCS(s1, i+1, s2, j));
        res = max(res, maxascLCS(s1, i, s2, j+1));

        return dp[i][j] = res;
    }

    int ascSum(const string& s){

        int total = 0;
        for(int i = 0 ; i < s.size() ; i ++)
            total += (int)s[i];
        return total;
    }
};

int main() {

    cout << Solution().minimumDeleteSum("sea", "eat") << endl;
    cout << Solution().minimumDeleteSum("delete", "leet") << endl;

    return 0;
}