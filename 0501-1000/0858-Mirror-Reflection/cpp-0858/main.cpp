/// Source : https://leetcode.com/problems/mirror-reflection/description/
/// Author : liuyubobobo
/// Time   : 2018-06-25

#include <iostream>
#include <cassert>

using namespace std;

/// Simulation
/// Time Complexity: O(p)
/// Space Complexity: O(1)
class Solution {
public:
    int mirrorReflection(int p, int q) {

        int d = 1;
        bool left = true;
        int y = 0;
        while(true){

            y += d * q;
            left = !left;
            if(y == p && left)
                return 2;
            else if(y == p && !left)
                return 1;
            else if(y == 0)
                return 0;

            if(y > p){
                assert(d == 1);
                y = p - (y - p);
                d = -1;
            }
            else if(y < 0){
                assert(d == -1);
                y = -y;
                d = 1;
            }
        }

        assert(false);
        return -1;
    }
};


int main() {

    cout << Solution().mirrorReflection(2, 1) << endl; // 2
    cout << Solution().mirrorReflection(4, 3) << endl; // 2
    cout << Solution().mirrorReflection(3, 2) << endl; // 0
    cout << Solution().mirrorReflection(3, 1) << endl; // 1

    return 0;
}