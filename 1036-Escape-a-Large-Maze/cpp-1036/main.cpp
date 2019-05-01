/// Source : https://leetcode.com/problems/escape-a-large-maze/
/// Author : liuyubobobo
/// Time   : 2019-04-27
#include <iostream>
#include <vector>
#include <set>

using namespace std;

/// DFS
/// Time Complexity: O(max_blocks^2)
/// Space Complexity: O(max_blocks^2)
class Solution {

private:
    const int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {

        set<pair<int, int>> blockset;
        for(const vector<int>& e: blocked)
            blockset.insert(make_pair(e[0], e[1]));

        set<pair<int, int>> visited;
        if(dfs(source[0], source[1], source[0], source[1], blockset, visited))
            return true;
        return visited.count(make_pair(target[0], target[1]));
    }

private:
    bool dfs(int x, int y, int sx, int sy,
             set<pair<int, int>>& blockset, set<pair<int, int>>& visited){

        visited.insert(make_pair(x, y));
        if(dis(x, y, sx, sy) > 200) return true;
        for(int i = 0; i < 4; i ++){
            int nextx = x + d[i][0], nexty = y + d[i][1];
            pair<int, int> next = make_pair(nextx, nexty);
            if(nextx >= 0 && nextx < 1000000 && nexty >= 0 && nexty < 1000000 &&
               !blockset.count(next) && !visited.count(next))
                if(dfs(nextx, nexty, sx, sy, blockset, visited))
                    return true;
        }
        return false;
    }

    int dis(int x0, int y0, int x1, int y1){
        return abs(x0 - x1) + abs(y0 - y1);
    }
};


int main() {

    return 0;
}