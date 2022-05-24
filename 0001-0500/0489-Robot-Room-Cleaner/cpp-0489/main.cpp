/// Source : https://leetcode.com/problems/robot-room-cleaner/
/// Author : liuyubobobo
/// Time   : 2022-05-24

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Simulation
/// Time Complexity: O(m * n)
/// Space Complexity: O(m * n)

/// This is the robot's control interface.
/// You should not implement it, or speculate about its implementation
class Robot {
public:
    // Returns true if the cell in front is open and robot moves into the cell.
    // Returns false if the cell in front is blocked and robot stays in the current cell.
    bool move();

    // Robot will stay in the same cell after calling turnLeft/turnRight.
    // Each turn will be 90 degrees.
     void turnLeft();
     void turnRight();

    // Clean the current cell.
     void clean();
};

class Solution {

private:
    set<pair<int, int>> visited;
    const int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

public:
    void cleanRoom(Robot& robot) {

        int d = 0;
        dfs(robot, 0, 0, d, visited);
    }

private:
    void dfs(Robot& robot, int x, int y, int& d, set<pair<int, int>>& visited){

        robot.clean();
        visited.insert({x, y});

        robot.turnLeft();
        d = (d - 1 + 4) % 4;

        int L = ((x == 0 && y == 0) ? 4 : 3);
        for(int i = 0; i < L; i ++){
            int nx = x + dirs[d][0], ny = y + dirs[d][1];
            if(visited.count({nx, ny})){
                robot.turnRight();
                d = (d + 1) % 4;
            }
            else if(!robot.move()){
                robot.turnRight();
                d = (d + 1) % 4;
            }
            else{
                dfs(robot, nx, ny, d, visited);
                robot.turnLeft();
                d = (d - 1 + 4) % 4;
            }
        }

        robot.move();
    }
};


int main() {

    return 0;
}
