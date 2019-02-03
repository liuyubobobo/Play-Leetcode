/// Source : https://leetcode.com/problems/smallest-string-starting-from-leaf/
/// Author : liuyubobobo
/// Time   : 2019-02-02

#include <iostream>

using namespace std;


/// DFS
/// Time Complexity: O(n), where n is the nodes' number of the tree
/// Space Complexity: O(h), where h is the height of the tree

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {

        string cur = "", best = "";
        dfs(root, cur, best);
        return best;
    }

private:
    void dfs(TreeNode* node, string& cur, string& best){

        cur += ('a' + node->val);

        if(!node->left && !node->right){
            string s = cur;
            reverse(s.begin(), s.end());
            if(best == "" | s < best) best = s;
        }

        if(node->left) dfs(node->left, cur, best);
        if(node->right) dfs(node->right, cur, best);
        cur.pop_back();
    }
};


int main() {

    // [0,null,1]
    // "ba"
    return 0;
}