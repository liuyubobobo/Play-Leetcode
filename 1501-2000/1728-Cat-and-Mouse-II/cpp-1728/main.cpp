/// Source : https://leetcode.com/problems/cat-and-mouse-ii/
/// Author : liuyubobobo
/// Time   : 2021-01-18

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>

using namespace std;


/// Memory Search
/// Time Complexity: O(MAX_TURN * 2 * R * C * (catJump + mouseJump))
/// Space Complexity: O(MAX_TURN * 2 * R * C)
class Solution {

private:
    const int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    const int MAX_TURN = 64;
    int R, C, catJump, mouseJump, foodPos;

public:
    bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) {

        R = grid.size(), C = grid[0].size();
        this->catJump = catJump, this->mouseJump = mouseJump;

        int catPos, mousePos;
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++)
                if(grid[i][j] == 'C') catPos = i * C + j, grid[i][j] = '.';
                else if(grid[i][j] == 'M') mousePos = i * C + j, grid[i][j] = '.';
                else if(grid[i][j] == 'F') foodPos = i * C + j, grid[i][j] = '.';

        vector<int> dp(600000, -1);
        return mouseGo(grid, get_state(0, 0, mousePos, catPos), dp);
    }

private:
    bool mouseGo(const vector<string>& grid, int state, vector<int>& dp){

        if(dp[state] != -1) return dp[state];

        int counter, first, mousePos, catPos;
        de_state(state, counter, first, mousePos, catPos);
//        assert(first == 0);

        if(counter == MAX_TURN) return dp[state] = false;

        int mx = mousePos / C, my = mousePos % C;
        if(!catGo(grid, get_state(counter, 1, mousePos, catPos), dp))
            return dp[state] = true;

        for(int d = 0; d < 4; d ++)
            for(int step = 1; step <= mouseJump; step ++){
                int x = mx + dirs[d][0] * step, y = my + dirs[d][1] * step;
                if(!in_area(x, y) || grid[x][y] == '#') break;
                if(x * C + y == foodPos) return dp[state] = true;
                if(x * C + y == catPos) continue;

                int next_state = get_state(counter, 1, x * C + y, catPos);
                if(!catGo(grid, next_state, dp))
                    return dp[state] = true;
            }
        return dp[state] = false;
    }

    bool catGo(const vector<string>& grid, int state, vector<int>& dp){

        if(dp[state] != -1) return dp[state];

        int counter, first, mousePos, catPos;
        de_state(state, counter, first, mousePos, catPos);
//        assert(first == 1);

        int cx = catPos / C, cy = catPos % C;
        if(!mouseGo(grid, get_state(counter + 1, 0, mousePos, catPos), dp))
            return dp[state] = true;

        for(int d = 0; d < 4; d ++)
            for(int step = 1; step <= catJump; step ++){
                int x = cx + dirs[d][0] * step, y = cy + dirs[d][1] * step;
                if(!in_area(x, y) || grid[x][y] == '#') break;
                if(x * C + y == foodPos) return dp[state] = true;
                if(x * C + y == mousePos) return dp[state] = true;

                int next_state = get_state(counter + 1, 0, mousePos, x * C + y);
                if(!mouseGo(grid, next_state, dp))
                    return dp[state] = true;
            }
        return dp[state] = false;
    }

    bool in_area(int x, int y){
        return x >= 0 && x < R && y >= 0 && y < C;
    }

    int get_state(int counter, int first, int mousePos, int catPos){
        return counter * 2 * 64 * 64 + first * 64 * 64 + mousePos * 64 + catPos;
    }

    void de_state(int state, int& counter, int& first, int& mousePos, int& catPos){

        catPos = state % 64;
        state /= 64;
        mousePos = state % 64;

        state /= 64;

        first = state % 2;
        counter = state / 2;
    }
};


int main() {

    vector<string> grid1 = {
            "####F",
            "#C...",
            "M...."
    };
    cout << Solution().canMouseWin(grid1, 1, 2) << endl;
    // 1

    vector<string> grid2 = {
            "####.##",
            ".#C#F#.",
            "######.",
            "##M.###"
    };
    cout << Solution().canMouseWin(grid2, 3, 6) << endl;
    // 0

    vector<string> grid3 = {
            ".M...",
            "..#..",
            "#..#.",
            "C#.#.",
            "...#F"
    };
    cout << Solution().canMouseWin(grid3, 3, 1) << endl;
    // 1

    return 0;
}
