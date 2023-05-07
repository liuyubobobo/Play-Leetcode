/// Source : https://leetcode.com/problems/make-costs-of-paths-equal-in-a-binary-tree/
/// Author : liuyubobobo
/// Time   : 2023-05-06

#include <iostream>
#include <vector>

using namespace std;


/// DFS
/// Time Complexity: O(n)
/// Space Complexity: O(h)
class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {

        int res = 0;
        dfs(n, 0, cost, res);
        return res;
    }

private:
    int dfs(int n, int cur, const vector<int>& cost, int& res){

        if(2 * cur + 1 >= n) return cost[cur];

        int l = dfs(n, 2 * cur + 1, cost, res);
        int r = dfs(n, 2 * cur + 2, cost, res);
        res += abs(l - r);
        return max(l, r) + cost[cur];
    }
};


int main() {

    return 0;
}
