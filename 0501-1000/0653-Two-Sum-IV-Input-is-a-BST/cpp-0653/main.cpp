/// Source : https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
/// Author : liuyubobobo
/// Time   : 2022-03-20

#include <iostream>
#include <unordered_set>

using namespace std;


/// Using Set
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

private:
    unordered_set<int> table;

public:
    bool findTarget(TreeNode* root, int k) {

        table.clear();
        return dfs(root, k);
    }

private:
    bool dfs(TreeNode* node, int t){

        if(!node) return false;

        if(table.count(t - node->val)) return true;
        table.insert(node->val);
        return dfs(node->left, t) || dfs(node->right, t);
    }
};


int main() {

    return 0;
}
