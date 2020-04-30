/// Source : https://leetcode-cn.com/problems/programmable-robot/
/// Author : liuyubobobo
/// Time   : 2020-04-30

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;


/// Mathematics
/// Time Complexity: O(m + n)
/// Space Complexity: O(m + n)
class Solution {
public:
    bool robot(string command, vector<vector<int>>& obstacles, int x, int y) {

        unordered_map<int, unordered_set<int>> map;
        int cx = 0, cy = 0;
        map[0].insert(0);
        for(char c: command){
            if(c == 'U') cy += 1;
            else cx += 1;
            if(c)
            map[cx].insert(cy);
        }

        for(const vector<int> obstacle: obstacles){
            int a = obstacle[0], b = obstacle[1];
            if(a > x || b > y || (a >= x && b >= y)) continue;

            int m = a / cx;
            a %= cx;
            b -= cy * m;
            if(map.count(a) && map[a].count(b)) return false;
        }

        int m = x / cx;
        x %= cx;
        y -= cy * m;
        if(map.count(x) && map[x].count(y)) return true;
        return false;
    }
};


int main() {

    string command1 = "URR";
    vector<vector<int>> obstacles1 = {};
    cout << Solution().robot(command1, obstacles1, 3, 2) << endl;
    // 1

    string command2 = "URR";
    vector<vector<int>> obstacles2 = {{2, 2}};
    cout << Solution().robot(command2, obstacles2, 3, 2) << endl;
    // 0

    string command3 = "URR";
    vector<vector<int>> obstacles3 = {{4, 2}};
    cout << Solution().robot(command3, obstacles3, 3, 2) << endl;
    // 1

    string command4 = "UUR";
    vector<vector<int>> obstacles4 = {};
    cout << Solution().robot(command4, obstacles4, 3, 4) << endl;
    // 0

    return 0;
}