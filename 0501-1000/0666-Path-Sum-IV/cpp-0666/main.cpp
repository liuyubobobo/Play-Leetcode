/// Source : https://leetcode.com/problems/path-sum-iv/
/// Author : liuyubobobo
/// Time   : 2021-05-19

#include <iostream>
#include <vector>

using namespace std;


/// DFS
/// Time Complexity: O(8 * 4)
/// Space Complexity: O(8 * 4)
class Solution {
public:
    int pathSum(vector<int>& nums) {

        vector<vector<int>> tree(4, vector<int>(8, -1));
        for(int e: nums){
            int d = e / 100 - 1;
            int p = (e % 100) / 10 - 1;
            int v = e % 10;
            tree[d][p] = v;
        }

        int cur = 0;
        return dfs(0, 0, tree, cur);
    }

private:
    int dfs(int r, int c, vector<vector<int>>& tree, int cur){

        if(r == 3 || tree[r + 1][2 * c] == -1 && tree[r + 1][2 * c + 1] == -1)
            return tree[r][c] + cur;

        int res = 0;
        if(tree[r + 1][2 * c] != -1)
            res += dfs(r + 1, 2 * c, tree, cur + tree[r][c]);
        if(tree[r + 1][2 * c + 1] != -1)
            res += dfs(r + 1, 2 * c + 1, tree, cur + tree[r][c]);
        return res;
    }
};


int main() {

    vector<int> nums1 = {113,229,330,466};
    cout << Solution().pathSum(nums1) << endl;
    // 18

    vector<int> nums2 = {113,229,349,470,485};
    cout << Solution().pathSum(nums2) << endl;
    // 47

    return 0;
}
