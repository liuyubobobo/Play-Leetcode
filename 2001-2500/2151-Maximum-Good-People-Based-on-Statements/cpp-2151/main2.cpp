/// Source : https://leetcode.com/problems/maximum-good-people-based-on-statements/
/// Author : liuyubobobo
/// Time   : 2022-01-22

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(2^n * (n^2))
/// Space Complexity: O(1)
class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {

        int n = statements.size();

        vector<vector<int>> states(n + 1);
        int res = 0;
        for(int state = 0; state < (1 << n); state ++){
            int bitcnt = __builtin_popcount(state);
            if(bitcnt <= res) continue;
            if(ok(n, state, statements)) res = bitcnt;
        }
        return res;
    }

private:
    bool ok(int n, int state, const vector<vector<int>>& say){

        vector<bool> good(n, false);
        for(int i = 0; i < n; i ++)
            good[i] = !!(state & (1 << i));

        for(int i = 0; i < n; i ++){
            if(!good[i]) continue;

            for(int j = 0; j < n; j ++){
                if(say[i][j] == 2) continue;

                if(say[i][j] == 0 && good[j]) return false;
                if(say[i][j] == 1 && !good[j]) return false;
            }
        }
        return true;
    }
};


int main() {

    return 0;
}
