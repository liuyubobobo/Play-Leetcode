/// Source : https://leetcode.com/problems/max-increase-to-keep-city-skyline/description/
/// Author : liuyubobobo
/// Time   : 2018-03-24

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/// Ad-Hoc
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {

private:
    int N, M;

public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {

        N = grid.size();
        M = grid[0].size();

        vector<int> top_view = get_top_view(grid);
        assert(top_view.size() == M);

        vector<int> left_view = get_left_view(grid);
        assert(left_view.size() == N);

        int res = 0;
        for(int i = 0 ; i < N ; i ++)
            for(int j = 0 ; j < M ; j ++)
                res += (min(top_view[j], left_view[i]) - grid[i][j]);
        return res;
    }

private:
    vector<int> get_top_view(vector<vector<int>>& grid){

        vector<int> res;
        for(int j = 0 ; j < M ; j ++){
            int max_height = -1;
            for(int i = 0 ; i < N ; i ++)
                max_height = max(max_height, grid[i][j]);
            res.push_back(max_height);
        }
        return res;
    }

    vector<int> get_left_view(vector<vector<int>>& grid){

        vector<int> res;
        for(int i = 0 ; i < N ; i ++)
            res.push_back(*max_element(grid[i].begin(), grid[i].end()));
        return res;
    }
};


int main() {

    vector<vector<int>> grid = {{3,0,8,4}, {2,4,5,7}, {9,2,6,3}, {0,3,1,0}};
    cout << Solution().maxIncreaseKeepingSkyline(grid) << endl;

    return 0;
}