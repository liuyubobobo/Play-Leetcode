/// Source : https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/
/// Author : liuyubobobo
/// Time   : 2021-01-30

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {

        unordered_map<int, vector<int>> g;
        for(const vector<int>& p: adjacentPairs)
            g[p[0]].push_back(p[1]), g[p[1]].push_back(p[0]);

        int start = -1;
        for(const pair<int, vector<int>>& p: g)
            if(p.second.size() == 1){
                start = p.first;
                break;
            }

        vector<int> res = {start};
        int cur = g[start][0];
        while(g[cur].size() > 1){
            res.push_back(cur);
            cur = g[cur][0] == res[res.size() - 2] ? g[cur][1] : g[cur][0];
        }
        res.push_back(cur);

        return res;
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << " "; cout << endl;
}

int main() {

    vector<vector<int>> pair1 = {{2, 1}, {3, 4}, {3, 2}};
    print_vec(Solution().restoreArray(pair1));
    // 1 2 3 4

    vector<vector<int>> pair2 = {{4, -2}, {1, 4}, {-3, 1}};
    print_vec(Solution().restoreArray(pair2));
    // -2 4 1 -3

    vector<vector<int>> pair3 = {{100000, -100000}};
    print_vec(Solution().restoreArray(pair3));
    // 100000, -100000

    return 0;
}
