/// Source : https://leetcode.com/problems/cat-and-mouse/
/// Author : liuyubobobo
/// Time   : 2018-11-04

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <cassert>
#include <queue>

using namespace std;


/// Topological Sorting
/// Create the underlying graph and reverse graph explictly
///
/// Time Complexity: O(node * node * 2 * maxdegree)
/// Space Complexity: O(node * node * 2)
class Solution {

private:
    const int DRAW = 0, HOLE = 0, MOUSE = 1, CAT = 2;

public:
    int catMouseGame(vector<vector<int>>& graph) {

        int n = graph.size();

        unordered_map<int, int> dp;
        unordered_map<int, unordered_set<int>> g = constructG(graph, dp);

        unordered_map<int, unordered_set<int>> rg = reverseG(g);

        unordered_map<int, int> degree;
        queue<int> q;
        for(const pair<int, unordered_set<int>>& p: g){
            degree[p.first] = p.second.size();
            if(degree[p.first] == 0)
                q.push(p.first);
        }

        while(!q.empty()){
            int curkey = q.front();
            q.pop();

            int curmouse, curcat, curwho;
            get(curkey, curmouse, curcat, curwho);
            assert(dp.count(curkey));
            if(curmouse == MOUSE && curcat == CAT && curwho == MOUSE)
                return dp[curkey];

            for(int prekey: rg[curkey])
                if(!dp.count(prekey)){
                    int premouse, precat, prewho;
                    get(prekey, premouse, precat, prewho);

                    if(prewho == dp[curkey]){
                        degree[prekey] = 0;
                        dp[prekey] = dp[curkey];
                        q.push(prekey);
                    }
                    else{
                        degree[prekey] --;
                        if(degree[prekey] == 0){
                            int res = 3 - prewho;
                            for(int x: g[prekey]){
                                assert(dp.count(x) && dp[x] != prewho);
                                if(dp[x] == DRAW){
                                    res = DRAW;
                                    break;
                                }
                            }
                            dp[prekey] = res;
                            q.push(prekey);
                        }
                    }
                }

        }
        return 0;
    }

private:
    unordered_map<int, unordered_set<int>> reverseG(
            const unordered_map<int, unordered_set<int>>& g){

        unordered_map<int, unordered_set<int>> res;
        for(const pair<int, unordered_set<int>>& p: g){
            int u = p.first;
            for(int v: p.second)
                res[v].insert(u);
        }
        return res;
    }

    unordered_map<int, unordered_set<int>> constructG(
            const vector<vector<int>>& graph,
            unordered_map<int, int>& dp){

        unordered_map<int, unordered_set<int>> res;

        unordered_set<int> visited;
        stack<int> stack;
        stack.push(key(MOUSE, CAT, MOUSE));
        visited.insert(key(MOUSE, CAT, MOUSE));
        while(!stack.empty()){
            int curkey = stack.top();
            stack.pop();

            int curmouse, curcat, curwho;
            get(curkey, curmouse, curcat, curwho);

            if(curmouse == HOLE){
                dp[curkey] = MOUSE;
                res[curkey] = unordered_set<int>();
                continue;
            }

            if(curmouse == curcat){
                dp[curkey] = CAT;
                res[curkey] = unordered_set<int>();
                continue;
            }

            if(curwho == MOUSE){
                for(int x: graph[curmouse]){
                    int nextkey = key(x, curcat, CAT);
                    res[curkey].insert(nextkey);
                    if(!visited.count(nextkey)){
                        visited.insert(nextkey);
                        stack.push(nextkey);
                    }
                }
            }
            else{ // curwho == CAT
                for(int x: graph[curcat]) if(x){
                        int nextkey = key(curmouse, x, MOUSE);
                        res[curkey].insert(nextkey);
                        if(!visited.count(nextkey)){
                            visited.insert(nextkey);
                            stack.push(nextkey);
                        }
                    }
            }
        }

        return res;
    }

    int key(int mousepos, int catpos, int who){
        return (mousepos * 100 + catpos) * 100 + who;
    }

    void get(int key, int& mousepos, int& catpos, int& who){

        who = key % 100;
        key /= 100;
        catpos = key % 100;
        mousepos = key / 100;
    }

//     void printG(const unordered_map<int, unordered_set<int>>& g){
//         for(const pair<int, unordered_set<int>>& p: g){
//             cout << p.first << " : ";
//             for(int e: p.second)
//                 cout << e << " ";
//             cout << endl;
//         }
//         cout << "----------" << endl;
//     }
};


int main() {

    vector<vector<int>> g0 = {
            {2},{2},{0,1}
    };
    cout << Solution().catMouseGame(g0) << endl;
    // 2

    // 2-4-3-1
    // |\ /
    // 0-5
    vector<vector<int>> g1 = {
            {2,5},{3},{0,4,5},{1,4,5},{2,3},{0,2,3}
    };
    cout << Solution().catMouseGame(g1) << endl;
    // 0

    //   0-2
    //   | |
    // 4-3 1
    vector<vector<int>> g2 = {{2,3},{2},{0,1},{0,4},{3}};
    cout << Solution().catMouseGame(g2) << endl;
    // 2

    //     0-2
    //    /|/
    // 1-4 3
    vector<vector<int>> g3 = {{2,3,4},{4},{0,3},{0,2},{0,1}};
    cout << Solution().catMouseGame(g3) << endl;
    // 1

    // 0-2-1
    // |\|/
    // 3-4
    vector<vector<int>> g4 = {{2,3,4},{2,4},{0,1,4},{0,4},{0,1,2,3}};
    cout << Solution().catMouseGame(g4) << endl;
    // 2

    vector<vector<int>> g5 = {
            {6},{4},{9},{5},{1,5},
            {3,4,6},{0,5,10},{8,9,10},{7},{2,7},{6,7}};
    cout << Solution().catMouseGame(g5) << endl;
    // 1

    return 0;
}