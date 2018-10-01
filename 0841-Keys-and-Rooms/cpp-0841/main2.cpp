/// Source : https://leetcode.com/problems/keys-and-rooms/description/
/// Author : liuyubobobo
/// Time   : 2018-09-30

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// BFS
/// Time Compexity: O(V + E)
/// Space Complexity: O(V)
class Solution {

public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        int V = rooms.size();
        vector<bool> visited(V, false);

        int res = 0;
        queue<int> q;
        q.push(0);
        visited[0] = true;
        while(!q.empty()){
            int cur = q.front();
            q.pop();

            res ++;

            for(int next: rooms[cur])
                if(!visited[next]){
                    visited[next] = true;
                    q.push(next);
                }
        }

        return res == V;
    }
};


int main() {

    return 0;
}