/// Source : https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/
/// Author : liuyubobobo
/// Time   : 2022-05-07

#include <iostream>

using namespace std;


/// DFS
/// Time Complexity: O(n)
/// Space Complexity: O(h)

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
    int averageOfSubtree(TreeNode* root) {

        int res = 0;
        dfs(root, res);
        return res;
    }

private:
    // sum, cnt
    pair<int, int> dfs(TreeNode* node, int& res){

        if(!node) return {0, 0};

        int sum = node->val, cnt = 1;
        pair<int, int> left_res = dfs(node->left, res);
        pair<int, int> right_res = dfs(node->right, res);
        sum += left_res.first + right_res.first;
        cnt += left_res.second + right_res.second;

        res += sum / cnt == node->val;
        return {sum, cnt};
    }
};


int main() {

    return 0;
}
