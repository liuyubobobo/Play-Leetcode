/// Source : https://leetcode.com/problems/find-the-shortest-superstring/
/// Author : liuyubobobo
/// Time   : 2018-11-17

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>

using namespace std;


/// Memory Search
/// Pre-calculate overlapped to improve the performance
///
/// Time Complexity: O(2^n * n * n)
/// Space Complexity: O(2^n * n)
class Solution {

private:
    int n;
    unordered_map<int, string> dp;

public:
    string shortestSuperstring(vector<string>& A) {

        dp.clear();
        n = A.size();

        vector<vector<int>> overlaped(n, vector<int>(n));
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < n; j ++)
                for(int len = min(A[i].size(), A[j].size()); len >= 0; len --)
                    if(A[i].substr(A[i].size() - len, len) == A[j].substr(0, len)){
                        overlaped[i][j] = len;
                        break;
                    }

        int best = INT_MAX;
        string res = "";
        for(int i = 0; i < n; i ++){
            string tres = dfs(A, 0, i, overlaped);
            if(tres.size() < best){
                best = tres.size();
                res = tres;
            }
        }
        return res;
    }

private:
    string dfs(const vector<string>& A, int state, int index, const vector<vector<int>>& overlapped){

        if(state == (1 << n) - 1 - (1 << index))
            return A[index];

        int hash = state * 100 + index;
        if(dp.count(hash))
            return dp[hash];

        state |= (1 << index);

        int best = INT_MAX;
        string res;
        for(int i = 0; i < n; i ++)
            if((state & (1 << i)) == 0){
                string tres = dfs(A, state, i, overlapped);
                tres += A[index].substr(overlapped[i][index]);
                if(tres.size() < best){
                    best = tres.size();
                    res = tres;
                }
            }
        return dp[hash] = res;
    }
};


int main() {

    vector<string> A1 = {"alex","loves","leetcode"};
    string res1 = Solution().shortestSuperstring(A1);
    cout << res1 << endl;
    string ans1 = "alexlovesleetcode";
    assert(ans1.size() == res1.size());


    vector<string> A2 = {"wmiy","yarn","rnnwc","arnnw","wcj"};
    string res2 = Solution().shortestSuperstring(A2);
    cout << res2 << endl;
    string ans2 = "wmiyarnnwcj";
    assert(ans2.size() == res2.size());


    vector<string> A3 = {"chakgmeinq","lhdbntkf","mhkelhye","hdbntkfch","kfchakgme","wymhkelh","kgmeinqw"};
    string res3 = Solution().shortestSuperstring(A3);
    cout << res3 << endl;
    string ans3 = "lhdbntkfchakgmeinqwymhkelhye";
    assert(ans3.size() == res3.size());

    return 0;
}