/// Source : https://leetcode.com/problems/minimum-knight-moves/
/// Author : liuyubobobo
/// Time   : 2019-09-21

#include <iostream>
#include <map>
#include <queue>

using namespace std;


/// BFS
/// Time Complexity: O(|x| * |y|)
/// Space Complexity: O(|x| * |y|)
class Solution {

private:
    const int dirs[8][2] = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2},
                            {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

public:
    int minKnightMoves(int x, int y) {

        x = abs(x), y = abs(y);
        map<pair<int, int>, int> map;
        map[make_pair(0, 0)] = 0;
        queue<pair<int, int>> q;
        q.push(make_pair(0, 0));

        while(!q.empty()){
            pair<int, int> cur = q.front();
            q.pop();
            if(cur.first == x && cur.second == y) return map[cur];

            for(int d = 0; d < 8; d ++){
                int nextx = cur.first + dirs[d][0], nexty = cur.second + dirs[d][1];
                pair<int, int> next = make_pair(nextx, nexty);
                if(in_area(nextx, nexty, x, y) && !map.count(next))
                    map[next] = map[cur] + 1, q.push(next);
            }
        }
        return -1;
    }

private:
    bool in_area(int x, int y, int X, int Y){
        return -5 <= x && x <= X + 5 && -5 <= y && y <= Y + 5;
    }
};


int main() {

    return 0;
}