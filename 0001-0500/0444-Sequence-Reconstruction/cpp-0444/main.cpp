/// Source : https://leetcode.com/problems/sequence-reconstruction/
/// Author : liuyubobobo
/// Time   : 2022-07-22

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// Topological Sort
/// Time Complexity: O(n + m)
/// Space Complexity: O(n + m)
class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {

        int n = nums.size();

        vector<vector<int>> g(n);
        for(const vector<int>& seq: sequences){
            for(int i = 1; i < seq.size(); i ++){
                int a = seq[i - 1] - 1, b = seq[i] - 1;
                g[a].push_back(b);
            }
        }

        vector<int> indegrees(n, 0);
        for(int u = 0; u < n; u ++)
            for(int v: g[u]) indegrees[v] ++;

        queue<int> q;
        for(int u = 0; u < n; u ++)
            if(indegrees[u] == 0) q.push(u);

        vector<int> res;
        while(!q.empty()){
            if(q.size() > 1) return false;

            int u = q.front(); q.pop();
            res.push_back(u + 1);
            for(int v: g[u]){
                indegrees[v] --;
                if(indegrees[v] == 0) q.push(v);
            }
        }

        return res == nums;
    }
};


int main() {

    return 0;
}
