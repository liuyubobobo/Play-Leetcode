/// Source : https://leetcode.com/problems/minimum-flips-in-binary-tree-to-get-result/
/// Author : liuyubobobo
/// Time   : 2022-06-22

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>

using namespace std;


/// Tree DP
/// Time Complexity: O(n)
/// Space Complexity: O(n)
/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int minimumFlips(TreeNode* root, bool result) {

        vector<unordered_map<TreeNode*, int>> dp(2);
        return dfs(root, result, dp);
    }

private:
    int dfs(TreeNode* node, bool result, vector<unordered_map<TreeNode*, int>>& dp){

        if(node->left == nullptr && node->right == nullptr)
            return result != node->val;

        auto iter = dp[result].find(node);
        if(iter != dp[result].end()) return iter->second;

        if(node->val == 5){
            TreeNode* child = node->left ? node->left : node->right;
            return dp[result][node] = dfs(child, !result, dp);
        }

        TreeNode* node1 = node->left, *node2 = node->right;
        int res = INT_MAX;
        for(int res1 = 0; res1 <= 1; res1 ++)
            for(int res2 = 0; res2 <= 1; res2 ++)
                if(calc(res1, res2, node->val) == result)
                    res = min(res, dfs(node1, res1, dp) + dfs(node2, res2, dp));
        return dp[result][node] = res;
    }

    int calc(int a, int b, int op){
        switch(op){
            case 2: return a | b;
            case 3: return a & b;
            case 4: return a ^ b;
            default: assert(false);
        }
        return -1;
    }
};


int main() {

    return 0;
}
