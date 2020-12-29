/// Source : https://leetcode.com/problems/where-will-the-ball-fall/
/// Author : liuyubobobo
/// Time   : 2020-12-29

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(m * n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {

        int R = grid.size(), C = grid[0].size();
        vector<int> res(C, -1);
        for(int j = 0; j < C; j ++){
            int curx = 0, cury = j;
            while(curx < R){
                if(grid[curx][cury] == 1){
                    if(cury + 1 >= C || grid[curx][cury + 1] == -1)
                        break;
                    else{
                        assert(grid[curx][cury + 1] == 1);
                        curx ++, cury ++;
                    }
                }
                else{ // grid[curx][cury] == -1
                    if(cury - 1 < 0 || grid[curx][cury - 1] == 1)
                        break;
                    else{
                        assert(grid[curx][cury - 1] == -1);
                        curx ++, cury --;
                    }
                }
                if(curx == R) res[j] = cury;
            }
        }
        return res;
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << " "; cout << endl;
}

int main() {

    vector<vector<int>> grid1 = {
            {1,1,1,-1,-1},
            {1,1,1,-1,-1},
            {-1,-1,-1,1,1},
            {1,1,1,1,-1},
            {-1,-1,-1,-1,-1}
    };
    print_vec(Solution().findBall(grid1));
    // 1 -1 -1 -1 -1

    vector<vector<int>> grid2 = {
            {-1}
    };
    print_vec(Solution().findBall(grid2));
    // -1

    return 0;
}
