/// Source : https://leetcode.cn/contest/hhrc2022/problems/wFtovi/
/// Author : liuyubobobo
/// Time   : 2022-10-04

#include <iostream>
#include <map>
#include <tuple>

using namespace std;


/// Tree DP
/// Time Complexity: O(n)
/// Space Complexity: O(n)

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

private:
    const int INF = INT_MAX / 2;

public:
    int minSupplyStationNumber(TreeNode* root) {

        map<tuple<TreeNode*, int, int>, int> dp;
        return dfs(root, 0, 0, dp);
    }

private:
    int dfs(TreeNode* node, int covered, int must_set, map<tuple<TreeNode*, int, int>, int>& dp){

        if(!node) return must_set ? INF : 0;

        tuple<TreeNode*, int, int> state = {node, covered, must_set};
        auto iter = dp.find(state);
        if(iter != dp.end()) return iter->second;

        int res = INF;
        if(must_set){
            res = min(res, 1 + dfs(node->left, 1, 0, dp) + dfs(node->right, 1, 0, dp));
        }
        else if(covered){
            res = min(res, 1 + dfs(node->left, 1, 0, dp) + dfs(node->right, 1, 0, dp));
            res = min(res, dfs(node->left, 0, 0, dp) + dfs(node->right, 0, 0, dp));
        }
        else{
            res = min(res, 1 + dfs(node->left, 1, 0, dp) + dfs(node->right, 1, 0, dp));
            if(node->left){
                res = min(res, dfs(node->left, 1, 1, dp) + dfs(node->right, 0, 0, dp));
                res = min(res, dfs(node->left, 1, 1, dp) + dfs(node->right, 1, 1, dp));
            }
            if(node->right){
                res = min(res, dfs(node->left, 0, 0, dp) + dfs(node->right, 1, 1, dp));
                res = min(res, dfs(node->left, 1, 1, dp) + dfs(node->right, 1, 1, dp));
            }
        }
        return dp[state] = res;
    }
};


int main() {

    return 0;
}
