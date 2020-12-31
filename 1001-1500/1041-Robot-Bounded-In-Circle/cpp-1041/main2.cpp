/// Source : https://leetcode.com/problems/robot-bounded-in-circle/
/// Author : liuyubobobo
/// Time   : 2019-05-19

#include <iostream>
#include <set>

using namespace std;


/// Just Simulation one instructions sequence
/// If the robot's direction is not still north
/// It can definitely go back!
///
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {

private:
    const int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

public:
    bool isRobotBounded(string instructions) {

        int curd = 0;
        pair<int, int> cur = make_pair(0, 0);
        for(char c: instructions){
            if(c == 'G'){
                cur.first += d[curd][0];
                cur.second += d[curd][1];
            }
            else if(c == 'L')
                curd = (curd + 3) % 4;
            else
                curd = (curd + 1) % 4;
        }
        return (!cur.first && !cur.second) || curd;
    }
};


int main() {

    string ins1 = "RRGRRGLLLRLGGLGLLGRLRLGLRLRRGLGGLLRRRLRLRLLGRGLGRRRGRLG";
    cout << Solution().isRobotBounded(ins1) << endl;
    // 0

    string ins2 = "GGLLGG";
    cout << Solution().isRobotBounded(ins2) << endl;
    // 1

    string ins3 = "GG";
    cout << Solution().isRobotBounded(ins3) << endl;
    // 0

    string ins4 = "GL";
    cout << Solution().isRobotBounded(ins4) << endl;
    // 1

    return 0;
}