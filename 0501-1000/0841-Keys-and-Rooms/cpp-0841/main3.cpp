/// Source : https://leetcode.com/problems/keys-and-rooms/description/
/// Author : liuyubobobo
/// Time   : 2018-09-30

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


/// DFS
/// Using Stack - non recursion algorithm
///
/// Time Compexity: O(V + E)
/// Space Complexity: O(V)
class Solution {

public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        int V = rooms.size();
        vector<bool> visited(V, false);

        int res = 0;
        stack<int> stack;
        stack.push(0);
        visited[0] = true;
        while(!stack.empty()){
            int cur = stack.top();
            stack.pop();

            res ++;

            for(int next: rooms[cur])
                if(!visited[next]){
                    visited[next] = true;
                    stack.push(next);
                }
        }

        return res == V;
    }
};


int main() {

    return 0;
}