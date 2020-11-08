/// Source : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-ii/
/// Author : liuyubobobo
/// Time   : 2020-11-08

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/// Using HashSet
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
    unordered_set<TreeNode*> set;
    TreeNode* res;

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        dfs(root, p, 1);
        if(set.empty()) return NULL;

        res = NULL;
        dfs(root, q, 2);
        return res;
    }

private:
    bool dfs(TreeNode* node, TreeNode* target, int type){

        if(node == target){
            if(type == 1) set.insert(node);
            else if(!res && set.count(node)) res = node;
            return true;
        }

        if(!node) return false;

        if(dfs(node->left, target, type) || dfs(node->right, target, type)){
            if(type == 1) set.insert(node);
            else if(!res && set.count(node)) res = node;
            return true;
        }
        return false;
    }
};


int main() {

    return 0;
}
