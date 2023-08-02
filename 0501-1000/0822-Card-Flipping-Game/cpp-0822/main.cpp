/// Source : https://leetcode.com/problems/card-flipping-game/description/
/// Author : liuyubobobo
/// Time   : 2023-08-01

#include <iostream>
#include <vector>
#include <climits>

using namespace std;


/// Brute Force
/// Time Complexity: O(n^2)
/// Space Complexity: O(1)
class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {

        int n = fronts.size(), res = INT_MAX;
        for(int i = 0; i < n; i ++){
            int x = fronts[i], y = backs[i];
            if(x == y) continue;
            if(x < res && ok(x, n, fronts, backs, i)) res = min(res, x);
            if(y < res && ok(y, n, fronts, backs, i)) res = min(res, y);
        }
        return res == INT_MAX ? 0 : res;
    }

private:
    bool ok(int x, int n, const vector<int>& fronts, const vector<int>& backs,
            int del_idx){

        for(int i = 0; i < fronts.size(); i ++)
            if(i != del_idx && fronts[i] == x && backs[i] == x)
                return false;
        return true;
    }
};


int main() {

    return 0;
}
