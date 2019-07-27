/// Source : https://leetcode.com/problems/parallel-courses/
/// Author : liuyubobobo
/// Time   : 2019-07-25

#include <iostream>
#include <vector>

using namespace std;


/// Topological Sort
/// Time Complexity: O(E)
/// Space Complexity: O(V)
class Solution {
public:
    int minimumSemesters(int N, vector<vector<int>>& relations) {

        vector<vector<int>> g(N);
        vector<int> degrees(N, 0);
        for(vector<int>& e: relations)
            g[--e[0]].push_back(--e[1]), degrees[e[1]] ++;

        int num = 0, res = 0;
        vector<int> q;
        for(int i = 0; i < N; i ++)
            if(degrees[i] == 0) q.push_back(i), num ++;
        while(!q.empty()){
            vector<int> next;
            for(int v: q)
                for(int w: g[v]){
                    degrees[w] --;
                    if(!degrees[w])
                        next.push_back(w), num ++;
                }
            res ++;
            q = next;
        }
        return num == N ? res : -1;
    }
};


int main() {
    vector<vector<int>> relations1 = {{1,3},{2,3}};
    cout << Solution().minimumSemesters(3, relations1) << endl;
    return 0;
}