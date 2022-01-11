/// Source : https://leetcode.com/problems/escape-a-large-maze/
/// Author : liuyubobobo
/// Time   : 2022-01-10

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>

using namespace std;


/// BFS
/// Time Complexity: O(|blocks|^2)
/// Space Complexity: O(|blocks|^2)
class Solution {

private:
    const int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int N = 1000000;

public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {

        set<pair<int, int>> blockset;
        for(const vector<int>& e: blocked)
            blockset.insert({e[0], e[1]});

        return bfs(source[0], source[1], target[0], target[1], blockset) &&
               bfs(target[0], target[1], source[0], source[1], blockset);
    }

private:
    bool bfs(int sx, int sy, int tx, int ty,
             set<pair<int, int>>& blockset){

        int L = blockset.size();

        queue<pair<int, int>> q;
        map<pair<int, int>, int> dis;
        q.push({sx, sy});
        dis[{sx, sy}] = 0;

        int maxv = 0;
        while(!q.empty()){
            int cx = q.front().first, cy = q.front().second, v = dis[{cx, cy}];
            q.pop();

            if(cx == tx && cy == ty) return true;

            maxv = max(maxv, v);
            if(v == L) continue;

            for(int d = 0; d < 4; d ++){
                int nx = cx + dirs[d][0], ny = cy + dirs[d][1];
                if(in_area(nx, ny) && !blockset.count({nx, ny}) && !dis.count({nx, ny})){
                    q.push({nx, ny});
                    dis[{nx, ny}] = v + 1;
                }
            }
        }
        return maxv >= L;
    }

    bool in_area(int x, int y){
        return x >= 0 && x < N && y >= 0 && y < N;
    }
};


int main() {

    vector<vector<int>> block1 = {
            {691938,300406},{710196,624190},{858790,609485},{268029,225806},
            {200010,188664},{132599,612099},{329444,633495},{196657,757958},{628509,883388}
    };
    vector<int> source1 = {655988,180910}, target1 = {267728,840949};
    cout << Solution().isEscapePossible(block1, source1, target1) << endl;
    // 1

    return 0;
}