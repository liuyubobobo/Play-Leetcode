/// Source : https://leetcode.com/problems/validate-binary-tree-nodes/
/// Author : liuyubobobo
/// Time   : 2020-02-22
/// Updated: 2023-10-31

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <numeric>

using namespace std;


/// topo sort
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {

        vector<set<int>> g(n);
        vector<int> indegrees(n, 0);
        for(int i = 0; i < n; i ++){
            if(leftChild[i] != -1){
                g[i].insert(leftChild[i]);
                indegrees[leftChild[i]] ++;
            }
            if(rightChild[i] != -1){
                if(g[i].count(rightChild[i])) return false;
                g[i].insert(rightChild[i]);
                indegrees[rightChild[i]] ++;
            }
        }

        return topo_sort(n, g, indegrees);
    }

private:
    bool topo_sort(int n, const vector<set<int>>& g, vector<int>& indegrees){

        for(int i = 0; i < n; i ++)
            if(indegrees[i] > 1 || g[i].size() > 2) return false;

        queue<int> q;
        vector<bool> visited(n, false);

        for(int i = 0; i < n; i ++)
            if(indegrees[i] == 0){
                q.push(i);
                visited[i] = true;
            }

        if(q.size() != 1) return false;

        while(!q.empty()){
            int cur = q.front(); q.pop();
            for(int next: g[cur]){
                if(visited[next]) return false;
                visited[next] = true;
                q.push(next);
            }
        }

        return accumulate(visited.begin(), visited.end(), 0) == n;
    }
};


int main() {

    vector<int> leftChild1 = {1, -1, 3, -1}, rightChild1 = {2, -1, -1, -1};
    cout << Solution().validateBinaryTreeNodes(4, leftChild1, rightChild1) << endl;
    // 1

    return 0;
}
