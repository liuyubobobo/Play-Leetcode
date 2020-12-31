/// Source : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iv/
/// Author : liuyubobobo
/// Time   : 2020-12-02

#include <iostream>
#include <unordered_set>
#include <vector>
#include <cassert>

using namespace std;


/// DFS
/// Time Complexity: O(n)
/// Space Complexity: O(h + |nodes|)

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
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {

        unordered_set<TreeNode*> target(nodes.begin(), nodes.end());

        TreeNode* res = NULL;
        dfs(root, 0, target, res);
        return res;
    }

private:
    int dfs(TreeNode* node, int depth, const unordered_set<TreeNode*>& set,
            TreeNode*& res){

        if(!node) return 0;

        int cnt = set.count(node);
        if(node->left) cnt += dfs(node->left, depth + 1, set, res);
        if(node->right) cnt += dfs(node->right, depth + 1, set, res);

        if(cnt == set.size() && !res) res = node;
        cout << node->val << " " << cnt << endl;
        return cnt;
    }
};


int main() {

    return 0;
}
