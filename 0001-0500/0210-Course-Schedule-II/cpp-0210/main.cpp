/// Source : https://leetcode.com/problems/course-schedule-ii/
/// Author : liuyubobobo
/// Time   : 2018-12-16

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// Using Priority Queue
/// Time Complexity: O(ElogE)
/// Space Complexity: O(V + E)
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> pre(numCourses, 0);
        vector<vector<int>> g(numCourses);
        for(const pair<int, int>& p: prerequisites){
            int from = p.second;
            int to = p.first;
            g[from].push_back(to);
            pre[to] ++;
        }

        for(int i = 0; i < numCourses; i ++)
            pq.push(make_pair(pre[i], i));

        vector<bool> learnt(numCourses, false);
        vector<int> res;
        while(!pq.empty()){
            int x = pq.top().first;
            int id = pq.top().second;
            pq.pop();

            if(!learnt[id]){
                if(x) return {};

                res.push_back(id);
                learnt[id] = true;

                for(int next: g[id]){
                    pre[next] --;
                    pq.push(make_pair(pre[next], next));
                }
            }
        }

        return res;
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