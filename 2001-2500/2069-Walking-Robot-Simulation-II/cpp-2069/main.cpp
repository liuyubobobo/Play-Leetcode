/// Source : https://leetcode.com/problems/walking-robot-simulation-ii/
/// Author : liuyubobobo
/// Time   : 2021-11-14

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Simulation
/// Time Complexity: init: O(1)
///                  move: O(with + height)
///                  get: O(1)
class Robot {

private:
    int W, H;
    int cx = 0, cy = 0;
    int d = 3;
    const int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    bool first = true;

public:
    Robot(int width, int height) : W(width), H(height){}

    void move(int num) {

        if(num) first = false;
        num %= (2 * (W + H - 2));

        while(num){
            int nx = cx + dirs[d][0], ny = cy + dirs[d][1];
            if(in_area(nx, ny)){
                cx = nx, cy = ny;
                num --;
            }
            else d = (d + 1) % 4;
        }
    }

    vector<int> getPos() {
        return {cx, cy};
    }

    string getDir() {
        if(first || d == 0) return "East";
        if(d == 1) return "North";
        if(d == 2) return "West";
        assert(d == 3);
        return "South";
    }

private:
    bool in_area(int x, int y){
        return x >= 0 && x < W && y >= 0 && y < H;
    }
};


int main() {

    return 0;
}
