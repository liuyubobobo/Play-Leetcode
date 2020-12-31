/// Source : https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/
/// Author : liuyubobobo
/// Time   : 2019-09-21

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;


/// Two Level Topological Sorting
/// Time Complexity: O(n)
/// Space Complexity: O(n + sum(|beforeItems[i]|))
class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {

        for(int& e: group) if(e == -1) e = m ++;

        vector<unordered_set<int>> groupG(m);
        vector<unordered_set<int>> from(m);
        vector<unordered_set<int>> groupv(m);
        for(int i = 0; i < n; i ++){
            groupv[group[i]].insert(i);
            if(!beforeItems[i].empty()){
                for(int e: beforeItems[i]){
                    if(group[e] != group[i]){
                        groupG[group[e]].insert(group[i]);
                        from[group[i]].insert(group[e]);
                    }
                }
            }
        }

        vector<int> indegrees(m, 0);
        for(int i = 0; i < m; i ++)
            indegrees[i] = from[i].size();

        queue<int> q;
        for(int i = 0; i < m; i ++)
            if(indegrees[i] == 0) q.push(i);

        vector<int> res;
        while(!q.empty()){
            int groupid = q.front();
            q.pop();

            if(!organize(groupv[groupid], beforeItems, res))
                return {};

            for(int e: groupG[groupid]){
                indegrees[e] --;
                if(indegrees[e] == 0)
                    q.push(e);
            }
        }

        return res.size() == n ? res : vector<int>();
    }

private:
    bool organize(const unordered_set<int>& points, const vector<vector<int>>& beforeItems,
                  vector<int>& res){

        unordered_map<int, unordered_set<int>> g;
        unordered_map<int, int> indegrees;
        for(int p: points) indegrees[p] = 0, g[p] = {};
        for(int p: points)
            if(!beforeItems[p].empty()){
                for(int e: beforeItems[p])
                    if(points.count(e))
                        g[e].insert(p), indegrees[p] ++;
            }

        queue<int> q;
        for(const pair<int, int>& indegree: indegrees)
            if(indegree.second == 0) q.push(indegree.first);

        vector<int> r;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            r.push_back(cur);

            for(int e: g[cur]){
                indegrees[e] --;
                if(indegrees[e] == 0) q.push(e);
            }
        }

        if(r.size() != points.size()) return false;

        for(int e: r) res.push_back(e);
        return true;
    }
};


void print_vector(const vector<int>& vec){
    for(int e: vec) cout << e << " "; cout << endl;
}

int main() {

    vector<int> group1 = {-1,-1,1,0,0,1,0,-1};
    vector<vector<int>> beforItems1 = {{},{6},{5},{6},{3,6},{},{},{}};
    print_vector(Solution().sortItems(8, 2, group1, beforItems1));

    return 0;
}