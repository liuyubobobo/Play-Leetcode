/// Source : https://leetcode-cn.com/problems/chuan-di-xin-xi/
/// Author : liuyubobobo
/// Time   : 2020-04-17

#include <iostream>
#include <vector>
#include <set>

using namespace  std;


/// Brute Force
/// Time Complexity: O(n^k)
/// Space Complexity: O(n + |relation| + k)
class Solution {

public:
    int numWays(int n, vector<vector<int>>& relation, int k) {

        vector<set<int>> g(n);
        for(const vector<int>& arc: relation)
            g[arc[0]].insert(arc[1]);

        return dfs(g, 0, n - 1, k);
    }

private:
    int dfs(const vector<set<int>>& g, int start, int end, int step){

        if(step == 0) return start == end;

        int res = 0;
        for(int next: g[start])
            res += dfs(g, next, end, step - 1);
        return res;
    }
};


int main() {

    return 0;
}
