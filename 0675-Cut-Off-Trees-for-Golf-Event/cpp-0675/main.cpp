/// Source : https://leetcode.com/problems/cut-off-trees-for-golf-event/description/
/// Author : liuyubobobo
/// Time   : 2017-11-03

#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

/// BFS
class Solution {

private:
    int n, m;
    bool visited[50][50];

public:
    int cutOffTree(vector<vector<int>>& forest) {

        if(forest.size() == 0)
            return -1;

        n = forest.size();
        m = forest[0].size();

        map<int, pair<int, int>> order;
        order[1] = make_pair(0, 0);
        for(int i = 0 ; i < n ; i ++)
            for(int j = 0 ; j < m ; j ++)
                if(forest[i][j] > 1)
                    order[forest[i][j]] = make_pair(i, j);

//        for(pair<int, pair<int, int>> e: order)
//            cout << e.first << " ( " << e.second.first << " , " << e.second.second << ")" << endl;

        int res = 0;
        for(int i = 1 ; i < order.size() ; i ++){
            map<int, pair<int, int>>::iterator start = order.begin();
            advance(start, i-1);

            map<int, pair<int, int>>::iterator end = order.begin();
            advance(end, i);

            int tres = bfs(forest, start->second, end->second);
            if(tres == -1)
                return -1;

            res += tres;
        }

        return res;
    }

private:
    int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int bfs(const vector<vector<int>>& forest,
            pair<int, int> start, pair<int, int> end){

//        cout << "Find path from (" << start.first << "," << start.second << ")";
//        cout << " to (" << end.first << "," << end.second << ")" << endl;
        for(int i = 0 ; i < n; i ++)
            for(int j = 0 ; j < m ; j ++)
                visited[i][j] = false;

        queue<pair<pair<int, int>, int>> q;
        q.push(make_pair(start, 0));
        visited[start.first][start.second] = true;
        while(!q.empty()){
            pair<pair<int, int>, int> e = q.front();
            int x = e.first.first;
            int y = e.first.second;
            int dis = e.second;
//            cout << "(" << x << "," << y << ") " << dis << endl;

            if(x == end.first && y == end.second)
                return dis;

            q.pop();

            for(int i = 0 ; i < 4 ; i ++){
                int newX = x + d[i][0];
                int newY = y + d[i][1];
                if(inArea(newX, newY) && !visited[newX][newY] && forest[newX][newY] > 0){
                    visited[newX][newY] = true;
                    q.push(make_pair(make_pair(newX, newY), dis + 1));
                }
            }
        }

        return -1;
    }

    bool inArea(int x, int y){
        return x >= 0 && x < n && y >= 0 && y < m;
    }
};


int main() {

    int forest1[3][3] = {
            {1, 2, 3},
            {0, 0, 4},
            {7, 6, 5}
    };
    vector<vector<int>> vec1;
    for(int i = 0 ; i < 3 ; i ++)
        vec1.push_back(vector<int>(forest1[i], forest1[i] + 3));
    cout << Solution().cutOffTree(vec1) << endl;
    // 6

    // ---

    int forest2[3][3] = {
            {1, 2, 3},
            {0, 0, 0},
            {7, 6, 5}
    };
    vector<vector<int>> vec2;
    for(int i = 0 ; i < 3 ; i ++)
        vec2.push_back(vector<int>(forest2[i], forest2[i] + 3));
    cout << Solution().cutOffTree(vec2) << endl;
    // -1

    // ---

    int forest3[3][3] = {
            {2, 3, 4},
            {0, 0, 5},
            {8, 7, 6}
    };
    vector<vector<int>> vec3;
    for(int i = 0 ; i < 3 ; i ++)
        vec3.push_back(vector<int>(forest3[i], forest3[i] + 3));
    cout << Solution().cutOffTree(vec3) << endl;
    // 6

    return 0;
}