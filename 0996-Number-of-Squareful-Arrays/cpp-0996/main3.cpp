/// Source : https://leetcode.com/problems/number-of-squareful-arrays/
/// Author : liuyubobobo
/// Time   : 2019-02-19

#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>

using namespace std;


/// Memory Search
/// Divide corresponding factorial number to avoid repeating counting :-)
/// Time Complexity: O(n*2^n)
/// Space Complexity: O(n*2^n)
class Solution {

private:
    int n;

public:
    int numSquarefulPerms(vector<int>& A) {

        n = A.size();

        vector<vector<int>> g(n);
        for(int i = 0; i < n; i ++)
            for(int j = i + 1; j < n; j ++)
                if(perfectSquare(A[i] + A[j])){
                    g[i].push_back(j);
                    g[j].push_back(i);
                }

        int res = 0;
        vector<vector<int>> dp(n, vector<int>(1 << n, -1));
        for(int i = 0; i < n; i ++)
            res += dfs(g, i, 1 << i, dp);

        unordered_map<int, int> freq;
        for(int e: A) freq[e] ++;
        for(const pair<int, int>& p: freq) res /= fac(p.second);
        return res;
    }

private:
    int dfs(const vector<vector<int>>& g,
            int index, int visited, vector<vector<int>>& dp){

        if(visited == (1 << n) - 1)
            return 1;

        if(dp[index][visited] != -1) return dp[index][visited];

        int res = 0;
        for(int next: g[index])
            if(!(visited & (1 << next))){
                visited += (1 << next);
                res += dfs(g, next, visited, dp);
                visited -= (1 << next);
            }
        return dp[index][visited] = res;
    }

    int fac(int x){
        if(x == 0 || x == 1) return 1;
        return x * fac(x - 1);
    }

    bool perfectSquare(int x){
        int t = sqrt(x);
        return t * t == x;
    }
};


int main() {

    vector<int> A1 = {1, 17, 8};
    cout << Solution().numSquarefulPerms(A1) << endl;
    // 2

    vector<int> A2 = {2, 2, 2};
    cout << Solution().numSquarefulPerms(A2) << endl;
    // 1

    vector<int> A3(12, 0);
    cout << Solution().numSquarefulPerms(A3) << endl;
    // 1

    return 0;
}