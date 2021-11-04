/// Source : https://leetcode.com/problems/number-of-spaces-cleaning-robot-cleaned/
/// Author : liuyubobobo
/// Time   : 2021-11-04

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Simualtion
/// Time Complexity: O(R * C)
/// Space Complexity: O(R * C)
class Solution {

private:
    const int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int R, C;

public:
    int numberOfCleanRooms(vector<vector<int>>& room) {

        R = room.size(), C = room[0].size();

        set<pair<int, int>> visited;
        set<int> res;
        int curx = 0, cury = 0, d = 0;
        visited.insert({curx * C + cury, d});
        res.insert(curx * C + cury);
        while(true){
            if(in_area(curx + dirs[d][0], cury + dirs[d][1]) && room[curx + dirs[d][0]][cury + dirs[d][1]] == 0)
                curx += dirs[d][0], cury += dirs[d][1];
            else
                d = (d + 1) % 4;

            if(visited.count({curx * C + cury, d})) break;
            visited.insert({curx * C + cury, d});
            res.insert(curx * C + cury);
        }
        return res.size();
    }

private:
    bool in_area(int x, int y){
        return 0 <= x && x < R && 0 <= y && y < C;
    }
};


int main() {

    return 0;
}
