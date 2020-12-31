/// Source : https://leetcode.com/problems/course-schedule-ii/
/// Author : liuyubobobo
/// Time   : 2018-12-16

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


/// Topological Order based on DFS
/// Time Complexity: O(V + E)
/// Space Complexity: O(V + E)
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {

        vector<vector<int>> g(numCourses);
        for(const pair<int, int>& p: prerequisites){
            int from = p.second;
            int to = p.first;
            g[from].push_back(to);
        }

        if(hasCircle(g)) return {};
        return topoOrder(g);
    }

private:
    bool hasCircle(const vector<vector<int>>& g){

        vector<bool> visited(g.size(), false);
        vector<bool> onPath(g.size(), false);
        for(int i = 0; i < g.size(); i ++)
            if(!visited[i])
                if(circleDFS(g, i, visited, onPath))
                    return true;
        return false;
    }

    bool circleDFS(const vector<vector<int>>& g, int v,
                   vector<bool>& visited, vector<bool>& onPath){

        visited[v] = true;
        onPath[v] = true;
        for(int next: g[v])
            if(!visited[next]){
                if(circleDFS(g, next, visited, onPath))
                    return true;
            }
            else if(onPath[next])
                return true;

        onPath[v] = false;
        return false;
    }

    vector<int> topoOrder(const vector<vector<int>>& g){

        vector<bool> visited(g.size(), false);
        stack<int> st;
        for(int i = 0; i < g.size(); i ++)
            if(!visited[i])
                topoDFS(g, i, visited, st);

        vector<int> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }

    void topoDFS(const vector<vector<int>>& g, int v, vector<bool>& visited, stack<int>& st){

        visited[v] = true;
        for(int next: g[v])
            if(!visited[next])
                topoDFS(g, next, visited, st);
        st.push(v);
    }
};


void print_vec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    vector<pair<int, int>> pre1 = {{1,0}};
    print_vec(Solution().findOrder(2, pre1));
    // 0 1

    vector<pair<int, int>> pre2 = {{1,0},{2,0},{3,1},{3,2}};
    print_vec(Solution().findOrder(4, pre2));
    // 0 1 2 3

    return 0;
}