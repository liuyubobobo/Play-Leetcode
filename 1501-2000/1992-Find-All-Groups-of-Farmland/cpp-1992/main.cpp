/// Source : https://leetcode.com/problems/find-all-groups-of-farmland/
/// Author : liuyubobobo
/// Time   : 2021-09-05

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(m * n)
/// Space Complexity: O(m * n)
class Solution {

private:
    int R, C;

public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {

        R = land.size(), C = land[0].size();
        vector<vector<int>> res;
        vector<vector<bool>> visited(R, vector<bool>(C, false));

        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++)
                if(land[i][j] == 1 && !visited[i][j]){
                    res.push_back(find_rec(land, i, j, visited));
                }
        return res;
    }

private:
    vector<int> find_rec(const vector<vector<int>>& land, int sx, int sy,
                         vector<vector<bool>>& visited){

        vector<int> res = {sx, sy};
        int i, j;
        for(i = sx; i < R; i ++)
            if(land[i][sy] == 0) break;

        for(j = sy; j < C; j ++)
            if(land[sx][j] == 0) break;

        res.push_back(i - 1);
        res.push_back(j - 1);

        for(int i = sx; i <= res[2]; i ++)
            for(int j = sy; j <= res[3]; j ++)
                visited[i][j] = true;
        return res;
    }
};


int main() {

    return 0;
}
