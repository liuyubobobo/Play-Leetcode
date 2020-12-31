/// Source : https://leetcode.com/problems/walking-robot-simulation/description/
/// Author : liuyubobobo
/// Time   : 2018-07-21

#include <iostream>
#include <vector>
#include <set>
#include <cassert>

using namespace std;


/// Simulation with TreeMap
/// Since in C++, you can not use unordered_set directly with pair...
///
/// Time Complexity: O(len(commands) * log(len(obstacles)))
/// Space Complexity: O(len(obstacles))
class Solution {

private:
    int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {

        set<pair<int, int>> obstacle_set;
        for(const vector<int> vec: obstacles)
            obstacle_set.insert(make_pair(vec[0], vec[1]));

        pair<int, int> pos = make_pair(0, 0);
        int direction = 0;
        int res = 0;
        for(int command: commands)
            if(command == -1)
                direction = (direction + 1) % 4;
            else if(command == -2)
                direction = (direction + 3) % 4;
            else{
                assert(command > 0);
                for(int i = 0 ; i < command ; i ++){
                    pair<int, int> nextpos = make_pair(pos.first + d[direction][0], pos.second + d[direction][1]);
                    if(obstacle_set.find(nextpos) == obstacle_set.end()){
                        pos = nextpos;
                        res = max(res, pos.first * pos.first + pos.second * pos.second);
//                        cout << "go to " << pos.first << " , " << pos.second << endl;
                    }
                    else
                        break;
                }
            }

        return res;
    }
};


int main() {

    vector<int> commands1 = {4, -1, 3};
    vector<vector<int>> obstacles1;
    cout << Solution().robotSim(commands1, obstacles1) << endl;
    // 25

    vector<int> commands2 = {4, -1, 4, -2, 4};
    vector<vector<int>> obstacles2 = {{2, 4}};
    cout << Solution().robotSim(commands2, obstacles2) << endl;
    // 65

    return 0;
}