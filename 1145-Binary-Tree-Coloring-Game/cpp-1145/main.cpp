/// Source : https://leetcode.com/problems/binary-tree-coloring-game/
/// Author : liuyubobobo
/// Time   : 2019-08-03

#include <iostream>
#include <unordered_map>

using namespace std;


/// Using HashSet to recoder subtree nodes' count
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
    TreeNode* target = NULL;
    unordered_map<TreeNode*, int> map;

public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {

        dfs(root, x);
        int a = map[target], b = n - a;
        if(b > a) return true;

        if(target->left){
            a = n - map[target->left], b = n - a;
            if(b > a) return true;
        }

        if(target->right){
            a = n - map[target->right], b = n - a;
            if(b > a) return true;
        }

        return false;
    }

private:
    int dfs(TreeNode* node, int t){

        if(!node) return 0;
        if(node->val == t) target = node;

        int res = 1;
        res += dfs(node->left, t);
        res += dfs(node->right, t);
        map[node] = res;
        return res;
    }
};


int main() {

    return 0;
}