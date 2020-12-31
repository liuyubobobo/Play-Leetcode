/// Source : https://leetcode.com/problems/find-the-shortest-superstring/
/// Author : liuyubobobo
/// Time   : 2018-11-17
/// Updated: 2020-04-29

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>

using namespace std;


/// Memory Search
/// Pre-calculate overlapped to improve the performance
/// Time Complexity: O(2^n * n * n)
/// Space Complexity: O(2^n * n)
class Solution {

private:
    int n;

public:
    string shortestSuperstring(vector<string>& A) {

        n = A.size();
        vector<vector<int>> dp(n, vector<int>(1 << n, -1));

        vector<vector<int>> overlaped(n, vector<int>(n, 0));
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < n; j ++)
                for(int len = min(A[i].size(), A[j].size()); len > 0; len --)
                    if(A[i].substr(A[i].size() - len, len) == A[j].substr(0, len)){
                        overlaped[i][j] = len;
                        break;
                    }

        int best = INT_MAX, start;
        for(int i = 0; i < n; i ++){
            int tres = dfs(A, 1 << i, i, overlaped, dp);
            if(tres < best) best = tres, start = i;
        }

        int state = (1 << start), cur = start;
        string res = A[start];
        while(state != ((1 << n) - 1)){
            for(int i = 0; i < n; i ++)
                if(i != cur && ((1 << i) & state) == 0 &&
                   dp[cur][state] == A[cur].size() + dp[i][state + (1 << i)] - overlaped[cur][i]){
                    res += A[i].substr(overlaped[cur][i]);
                    state += (1 << i);
                    cur = i;
                    break;
                }
        }
        return res;
    }

private:
    int dfs(const vector<string>& A, int state, int index,
            const vector<vector<int>>& overlapped, vector<vector<int>>& dp){

        if(dp[index][state] != -1) return dp[index][state];
        if(state == (1 << n) - 1) return dp[index][state] = A[index].size();

        int res = INT_MAX;
        for(int i = 0; i < n; i ++)
            if((state & (1 << i)) == 0){
                int tres = A[index].size() + dfs(A, state | (1 << i), i, overlapped, dp) - overlapped[index][i];
                res = min(res, tres);
            }
        return dp[index][state] = res;
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