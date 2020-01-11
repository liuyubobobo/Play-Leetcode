/// Source : https://leetcode.com/problems/jump-game-iii/
/// Author : liuyubobobo
/// Time   : 2020-01-11

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// BFS
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {

        queue<int> q;
        vector<bool> visited(arr.size(), false);

        q.push(start);
        visited[start] = true;
        while(!q.empty()){
            int cur = q.front();
            q.pop();

            if(!arr[cur]) return true;

            if(cur - arr[cur] >= 0 && !visited[cur - arr[cur]])
                q.push(cur - arr[cur]), visited[cur - arr[cur]] = true;
            if(cur + arr[cur] < arr.size() && !visited[cur + arr[cur]])
                q.push(cur + arr[cur]), visited[cur + arr[cur]] = true;
        }
        return false;
    }
};


int main() {

    return 0;
}
