/// Source : https://leetcode.com/problems/escape-the-ghosts/description/
/// Author : liuyubobobo
/// Time   : 2018-02-24

#include <iostream>
#include <vector>

using namespace std;


/// Manhattan Distance
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {

        int dis = abs(target[0]) + abs(target[1]);
        for(const vector<int>& p: ghosts){
            int g_dis = abs(p[0] - target[0]) + abs(p[1] - target[1]);
            if(g_dis <= dis)
                return false;
        }
        return true;
    }
};


void printBool(bool res){
    cout << (res ? "True" : "False") << endl;
}

int main() {

    vector<vector<int>> ghosts1 = {{1, 0}, {0, 3}};
    vector<int> target1 = {0, 1};
    printBool(Solution().escapeGhosts(ghosts1, target1));

    vector<vector<int>> ghosts2 = {{1, 0}};
    vector<int> target2 = {2, 0};
    printBool(Solution().escapeGhosts(ghosts2, target2));

    vector<vector<int>> ghosts3 = {{2, 0}};
    vector<int> target3 = {1, 0};
    printBool(Solution().escapeGhosts(ghosts3, target3));

    return 0;
}