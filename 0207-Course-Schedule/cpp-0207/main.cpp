/// Source : https://leetcode.com/problems/course-schedule-ii/
/// Author : liuyubobobo
/// Time   : 2018-12-16

#include <iostream>
#include <vector>

using namespace std;


/// Check Directed Graph has circle
/// Time Complexity: O(m + n)
/// Space Complexity: O(m + n)
class Solution {

public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {

        vector<vector<int>> g(numCourses);
        for(const pair<int, int>& p: prerequisites){
            int from = p.second;
            int to = p.first;
            g[from].push_back(to);
        }

        return hasCircle(g);
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
};


int main() {

    return 0;
}