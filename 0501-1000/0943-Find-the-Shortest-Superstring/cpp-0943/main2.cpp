/// Source : https://leetcode.com/problems/find-the-shortest-superstring/
/// Author : liuyubobobo
/// Time   : 2020-04-28

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(2^n * n * n)
/// Space Complexity: O(2^n * n)
class Solution {

public:
    string shortestSuperstring(vector<string>& A) {

        int n = A.size();
        if(n == 1) return A[0];

        vector<vector<int>> overlaped(n, vector<int>(n, 0));
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < n; j ++)
                for(int len = min(A[i].size(), A[j].size()); len > 0; len --)
                    if(A[i].substr(A[i].size() - len, len) == A[j].substr(0, len)){
                        overlaped[i][j] = len;
                        break;
                    }

        vector<vector<int>> dp(n, vector<int>(1 << n, -1));
        string res = "";
        for(int start = 0; start < n; start ++){
            dp[start][1 << start] = A[start].size();
            for(int state = 1; state < (1 << n); state ++)
                for(int i = 0; i < n; i ++){
                    if(dp[i][state] != -1){
                        for(int j = 0; j < n; j ++)
                            if(((1 << j) & state) == 0){
                                int t = dp[i][state] + A[j].size() - overlaped[i][j];
                                if(dp[j][(1 << j) | state] == -1)
                                    dp[j][(1 << j) | state] = t;
                                else if(t < dp[j][(1 << j) | state])
                                    dp[j][(1 << j) | state] = t;
                            }
                    }
                }

            int tlen = INT_MAX, tend;
            for(int end = 0; end < n; end ++)
                if(end != start && dp[end][(1 << n) - 1] < tlen)
                    tlen = dp[end][(1 << n) - 1], tend = end;

            int state = (1 << n) - 1, cur = tend;
            string tres = A[tend];
            while(true){
                if(state - (1 << cur) == 0) break;
                for(int i = 0; i < n; i ++)
                    if(i != cur && ((1 << i) & state) &&
                       dp[cur][state] == dp[i][state - (1 << cur)] + A[cur].size() - overlaped[i][cur]){
                        tres = A[i] + tres.substr(overlaped[i][cur]);
                        state -= (1 << cur);
                        cur = i;
                        break;
                    }
            }

            if(res == "" || tres.size() < res.size()) res = tres;
        }
        return res;
    }
};


int main() {

    vector<string> A1 = {"alex","loves","leetcode"};
    string res1 = Solution().shortestSuperstring(A1);
    cout << res1 << endl;
    // "alexlovesleetcode";

    vector<string> A2 = {"wmiy","yarn","rnnwc","arnnw","wcj"};
    string res2 = Solution().shortestSuperstring(A2);
    cout << res2 << endl;
    // "wmiyarnnwcj";

    vector<string> A3 = {"chakgmeinq","lhdbntkf","mhkelhye","hdbntkfch","kfchakgme","wymhkelh","kgmeinqw"};
    string res3 = Solution().shortestSuperstring(A3);
    cout << res3 << endl;
    // "lhdbntkfchakgmeinqwymhkelhye";

    return 0;
}