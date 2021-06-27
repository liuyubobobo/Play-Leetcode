/// Source : https://leetcode.com/problems/cyclically-rotating-a-grid/
/// Author : liuyubobobo
/// Time   : 2021-06-26

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(min(R * C) * R * C)
/// Space Complexity: O(R + C)
class Solution {

private:
    int R, C;

public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {

        R = grid.size(), C = grid[0].size();
        for(int index = 0; index < min(R, C) / 2; index ++){
            vector<int> data;
            get_data(grid, index, data);

//            cout << "o data:";
//            for(int e: data) cout << e << " "; cout << endl;

            int kk = k % data.size();
            vector<int> new_data(data.size());
            for(int i = 0; i < data.size(); i ++)
                new_data[i] = data[(i + kk) % data.size()];

//            cout << "new data:";
//            for(int e: new_data) cout << e << " "; cout << endl;

            set_data(grid, index, new_data);
        }

        return grid;
    }

private:
    void set_data(vector<vector<int>>& g, int k, const vector<int>& data){

        int index = 0;
        for(int j = k; j < C - k; j ++)
            g[k][j] = data[index ++];

        for(int i = k + 1; i < R - k; i ++)
            g[i][C - 1 - k] = data[index ++];

        for(int j = C - 1 - k - 1; j >= k; j --)
            g[R - k - 1][j] = data[index ++];

        for(int i = R - 1 - k - 1; i > k; i --)
            g[i][k] = data[index ++];
    }

    void get_data(const vector<vector<int>>& g, int k, vector<int>& data){

        for(int j = k; j < C - k; j ++)
            data.push_back(g[k][j]);

        for(int i = k + 1; i < R - k; i ++)
            data.push_back(g[i][C - 1 - k]);

        for(int j = C - 1 - k - 1; j >= k; j --)
            data.push_back(g[R - k - 1][j]);

        for(int i = R - 1 - k - 1; i > k; i --)
            data.push_back(g[i][k]);
    }
};


void print_g(const vector<vector<int>>& g){

    for(const vector<int>& row: g){
        for(int e: row) cout << e << " ";
        cout << endl;
    }
}

int main() {

    vector<vector<int>> grid1 = {
            {1,2,3,4},
            {5,6,7,8},
            {9,10,11,12},
            {13,14,15,16}
    };
    print_g(Solution().rotateGrid(grid1, 2));

    vector<vector<int>> grid2 = {
            {1,2,3,4},
            {16,1,2,5},
            {15,8,3,6},
            {14,7,4,7},
            {13,6,5,8},
            {12,11,10,9}
    };
    print_g(Solution().rotateGrid(grid2, 1));

    return 0;
}
