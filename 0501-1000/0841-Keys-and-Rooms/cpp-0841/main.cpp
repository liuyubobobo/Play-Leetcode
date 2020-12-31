/// Source : https://leetcode.com/problems/keys-and-rooms/description/
/// Author : liuyubobobo
/// Time   : 2018-09-30

#include <iostream>
#include <vector>

using namespace std;


/// DFS
/// Time Compexity: O(V + E)
/// Space Complexity: O(V)
class Solution {

public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        int V = rooms.size();
        vector<bool> visited(V, false);
        return dfs(rooms, 0, visited) == V;
    }

private:
    int dfs(const vector<vector<int>>& rooms, int v, vector<bool>& visited){

        visited[v] = true;

        int res = 1;
        for(int next: rooms[v])
            if(!visited[next])
                res += dfs(rooms, next, visited);
        return res;
    }
};


int main() {

    return 0;
}