/// Source : https://leetcode.com/problems/maximum-students-taking-exam/
/// Author : liuyubobobo
/// Time   : 2020-02-11

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/// Memory Search + State Compression
/// Time Complexity: O(m * 2 ^ n)
/// Space Complexity: O(m * 2 ^ n)
class Solution {

private:
    int m, n;

public:
    int maxStudents(vector<vector<char>>& seats) {

        m = seats.size(), n = seats[0].size();
        vector<vector<int>> dp(m, vector<int>(1 << n, -1));
        return dfs(seats, 0, -1, dp);
    }

private:
    int dfs(const vector<vector<char>>& seats, int row, int last,
            vector<vector<int>>& dp){

        if(row == m) return 0;

        if(last != -1 && dp[row][last] != -1) return dp[row][last];

        int res = 0;
        for(int cur = 0; cur < (1 << n); cur ++)
            if(ok(seats[row], cur, last)){
                int x = get_bits(cur);
                res = max(res, x + dfs(seats, row + 1, cur, dp));
            }
        // cout << row << " " << last << " " << res << endl;
        if(last == -1) return res;
        return dp[row][last] = res;
    }

    bool ok(const vector<char>& seats, int cur, int last){

        vector<int> vcur;
        for(int i = 0; i < n; i ++) vcur.push_back(cur % 2), cur /= 2;
        assert(vcur.size() == n);

        for(int i = 0; i < n; i ++)
            if(seats[i] == '#' && vcur[i]) return false;

        for(int i = 1; i < n; i ++)
            if(vcur[i - 1] && vcur[i]) return false;

        if(last != -1){
            vector<int> vlast;
            for(int i = 0; i < n; i ++) vlast.push_back(last % 2), last /= 2;
            assert(vlast.size() == n);

            for(int i = 0; i < n; i ++)
                if(vcur[i]){
                    if(i - 1 >= 0 && vlast[i - 1]) return false;
                    if(i + 1 < n && vlast[i + 1]) return false;
                }
        }
        return true;
    }

    int get_bits(int x){
        int res = 0;
        while(x) res += x % 2, x /= 2;
        return res;
    }
};


int main() {

    vector<vector<char>> seats1 = {
            {'#','.','#','#','.','#'},
            {'.','#','#','#','#','.'},
            {'#','.','#','#','.','#'}
    };
    cout << Solution().maxStudents(seats1) << endl;

    return 0;
}
