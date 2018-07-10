/// Source : https://leetcode.com/problems/shortest-path-to-get-all-keys/description/
/// Author : liuyubobobo
/// Time   : 2018-07-09

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <queue>

using namespace std;

/// Brute Force all Keys Permutation
/// Time Complexity: O(keys!*keys*n^2)
/// Space Complexity:O(keys + n^2)
class Solution {

private:
    int n, m;
    const int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    int shortestPathAllKeys(vector<string>& grid) {

        n = grid.size();
        m = grid[0].size();

        unordered_map<char, pair<int, int>> poi = getPOI(grid);

        vector<char> keys = getAllKeys(grid);
        sort(keys.begin(), keys.end());

        int res = INT_MAX;
        do{
            res = min(res, go(grid, keys, poi, res));
        }while(next_permutation(keys.begin(), keys.end()));

        if(res == INT_MAX)
            return -1;
        return res;
    }

private:
    int go(const vector<string>& grid, const vector<char>& keys,
           unordered_map<char, pair<int, int>>& poi, int curMinRes){

        vector<pair<int, int>> pos = {poi['@']};
        for(char key: keys)
            pos.push_back(poi[key]);

        int res = 0;
        unordered_set<char> ownKeys;
        for(int i = 1; i < pos.size() ; i ++){
            int need = go(grid, pos[i-1], pos[i], ownKeys);
            if(need == -1)
                return INT_MAX;

            res += need;
            if(res >= curMinRes)
                return INT_MAX;
            ownKeys.insert(keys[i-1]);
        }
        return res;
    }

    int go(const vector<string>& grid,
           const pair<int, int>& start, const pair<int, int>& end,
           const unordered_set<char>& ownKeys){

        queue<pair<pair<int, int>, int>> q;
        q.push(make_pair(start, 0));

        unordered_set<int> visited;
        visited.insert(start.first * m + start.second);

        while(!q.empty()){
            pair<int, int> cur = q.front().first;
            int step = q.front().second;
            q.pop();

            for(int i = 0 ; i < 4 ; i ++){
                int nextX = cur.first + d[i][0];
                int nextY = cur.second + d[i][1];
                if(nextX == end.first && nextY == end.second)
                    return step + 1;
                if(inArea(nextX, nextY) && grid[nextX][nextY] != '#' &&
                        visited.find(nextX * m + nextY) == visited.end()){

                    if(!isLock(grid[nextX][nextY]) ||
                            (isLock(grid[nextX][nextY]) && ownKeys.find(grid[nextX][nextY] - 'A' + 'a') != ownKeys.end())){
                        q.push(make_pair(make_pair(nextX, nextY), step + 1));
                        visited.insert(nextX * m + nextY);
                    }
                }
            }
        }
        return -1;
    }

    vector<char> getAllKeys(const vector<string>& grid){
        vector<char> res;
        for(int i = 0 ; i < n ; i ++)
            for(int j = 0 ; j < m ; j ++)
                if(isKey(grid[i][j]))
                    res.push_back(grid[i][j]);
        return res;
    }

    unordered_map<char, pair<int, int>> getPOI(const vector<string>& grid){
        unordered_map<char, pair<int, int>> res;
        for(int i = 0 ; i < n ; i ++)
            for(int j = 0 ; j < m ; j ++)
                if(grid[i][j] != '.' && grid[i][j] != '#'){
                    assert(grid[i][j] == '@' || isKey(grid[i][j]) || isLock(grid[i][j]));
                    assert(res.find(grid[i][j]) == res.end());
                    res[grid[i][j]] = make_pair(i, j);
                }
        return res;
    };

    bool isKey(char c){
        return c >= 'a' && c <= 'z';
    }

    bool isLock(char c){
        return c >= 'A' && c <= 'Z';
    }

    bool inArea(int x, int y){
        return x >= 0 && x < n && y >= 0 && y < m;
    }
};


int main() {

    vector<string> grid1 = {"@.a.#",
                            "###.#",
                            "b.A.B"};
    cout << Solution().shortestPathAllKeys(grid1) << endl;

    vector<string> grid2 = {"@..aA",
                            "..B#.",
                            "....b"};
    cout << Solution().shortestPathAllKeys(grid2) << endl;

    vector<string> grid3 = {"@abcdeABCDEFf"};
    cout << Solution().shortestPathAllKeys(grid3) << endl;

    vector<string> grid4 = {
            "#..#.#.#..#.#.#.....#......#..",
            ".#.......#....#A.....#.#......",
            "#....#.....#.........#........",
            "...#.#.........#..@....#....#.",
            ".#.#.##...#.........##....#..#",
            "..........#..#..###....##..#.#",
            ".......#......#...#...#.....c#",
            ".#...#.##......#...#.###...#..",
            "..........##...#.......#......",
            "#...#.........a#....#.#.##....",
            "..#..#...#...#..#....#.....##.",
            "..........#...#.##............",
            "...#....#..#.........#..D.....",
            "....#E.#....##................",
            "...........##.#.......#.#....#",
            "...#..#...#.#............#e...",
            "..#####....#.#...........##..#",
            "##......##......#.#...#..#.#..",
            ".#F.......#..##.......#....#..",
            "............#....#..#..#...#..",
            ".............#...#f...#..##...",
            "....#..#...##.........#..#..#.",
            ".....#.....##.###..##.#......#",
            ".#..#.#...#.....#........###..",
            ".....#.#...#...#.....#.....#..",
            "##.....#....B.....#..#b.......",
            ".####....##..#.##..d.#......#.",
            "..#.....#....##........##...##",
            "...#...#...C..#..#....#.......",
            "#.....##.....#.#......#......."
    };
    cout << Solution().shortestPathAllKeys(grid4) << endl;

    return 0;
}