/// Source : https://leetcode.com/problems/path-crossing/
/// Author : liuyubobobo
/// Time   : 2020-06-27

#include <iostream>
#include <set>

using namespace std;


/// Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    bool isPathCrossing(string path) {

        set<pair<int, int>> table;
        table.insert({0, 0});
        int x = 0, y = 0;
        for(char c: path){
            if(c == 'N') y ++;
            else if(c == 'E') x ++;
            else if(c == 'S') y --;
            else x --;

            if(table.count({x, y})) return true;
            table.insert({x, y});
        }
        return false;
    }
};


int main() {

    cout << Solution().isPathCrossing("NES") << endl;
    // 0

    cout << Solution().isPathCrossing("NESWW") << endl;
    // 1

    return 0;
}
