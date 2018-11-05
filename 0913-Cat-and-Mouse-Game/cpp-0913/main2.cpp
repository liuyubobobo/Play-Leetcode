/// Source : https://leetcode.com/problems/cat-and-mouse/
/// Author : liuyubobobo
/// Time   : 2018-11-05

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <cassert>
#include <queue>

using namespace std;


/// Topological Sorting
/// Without Creating the underlying graph and reverse graph explictly
/// Much much faster
///
/// BTW: There's a similar challenge in CodeSignal
/// This idea can pass it but the previous idea will lead to TLE
/// See https://app.codesignal.com/challenge/Q4sEyWz7Kw3QpyYC8 for more details :-)
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
        queue<int> q;

        for(int i = 1; i < n; i ++)
            for(int who = 1; who <= 2; who ++){

                int k = key(0, i, who);
                dp[k] = MOUSE;
                q.push(k);

                k = key(i, i, who);
                dp[k] = CAT;
                q.push(k);
            }

        unordered_map<int, int> degree;
        for(int i = 0; i < n; i ++)
            for(int j = 1; j < n; j ++){
                degree[key(i, j, MOUSE)] = graph[i].size();
                degree[key(i, j, CAT)] = graph[j].size();
                for(int x: graph[j])
                    if(!x) degree[key(i, j, CAT)] --;
            }

        while(!q.empty()){
            int curkey = q.front();
            q.pop();

            int curmouse, curcat, curwho;
            get(curkey, curmouse, curcat, curwho);
            assert(dp.count(curkey));
            if(curmouse == MOUSE && curcat == CAT && curwho == MOUSE)
                return dp[curkey];

            if(curwho == MOUSE){
                for(int precat: graph[curcat])
                    if(precat){
                        int prekey = key(curmouse, precat, CAT);
                        if(!dp.count(prekey))
                            process(curkey, prekey, dp, degree, q, graph);
                    }
            }
            else{ // curwho == CAT
                for(int premouse: graph[curmouse])
                    if(premouse != curcat){
                        int prekey = key(premouse, curcat, MOUSE);
                        if(!dp.count(prekey))
                            process(curkey, prekey, dp, degree, q, graph);
                    }
            }
        }
        return 0;
    }

private:
    void process(int curkey, int prekey, unordered_map<int, int>& dp,
                 unordered_map<int, int>& degree, queue<int>& q,
                 const vector<vector<int>>& graph){

        int curmouse, curcat, curwho;
        get(curkey, curmouse, curcat, curwho);

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
                if(prewho == MOUSE){
                    for(int x: graph[premouse])
                        if(x != curcat){
                            if(dp[key(x, precat, curwho)] == DRAW){
                                res = DRAW;
                                break;
                            }
                        }
                }
                else{ // prewho == CAT
                    for(int x: graph[precat])
                        if(x){
                            if(dp[key(premouse, x, curwho)] == DRAW){
                                res = DRAW;
                                break;
                            }
                        }
                }

                dp[prekey] = res;
                q.push(prekey);
            }
        }
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

};


int main() {

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