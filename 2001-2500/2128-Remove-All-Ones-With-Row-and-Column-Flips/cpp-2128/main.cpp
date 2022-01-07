/// Source : https://leetcode.com/problems/remove-all-ones-with-row-and-column-flips/
/// Author : liuyubobobo
/// Time   : 2022-01-06

#include <iostream>
#include <vector>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(R * C)
/// Space Complexity: O(1)
class Solution {
public:
    bool removeOnes(vector<vector<int>>& grid) {

        int R = grid.size(), C = grid[0].size();
        for(int j = 0; j < C; j ++)
            if(grid[0][j]){
                for(int i = 0; i < R; i ++) grid[i][j] ^= 1;
            }

        for(int i = 0; i < R; i ++)
            if(!ok(grid[i])) return false;
        return true;
    }

private:
    bool ok(const vector<int>& v){

        for(int i = 1; i < v.size(); i ++)
            if(v[i] != v[0]) return false;
        return true;
    }
};


int main() {

    return 0;
}
