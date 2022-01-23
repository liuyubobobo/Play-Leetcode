/// Source : https://leetcode.com/problems/maximum-good-people-based-on-statements/
/// Author : liuyubobobo
/// Time   : 2022-01-22

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(2^n * (n^2))
/// Space Complexity: O(2^n)
class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {

        int n = statements.size();

        vector<vector<int>> states(n + 1);
        for(int state = 0; state < (1 << n); state ++)
            states[__builtin_popcount(state)].push_back(state);

        for(int good_num = n; good_num > 0; good_num --)
            for(int state: states[good_num])
                if(ok(n, state, statements)) return good_num;
        return 0;
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
