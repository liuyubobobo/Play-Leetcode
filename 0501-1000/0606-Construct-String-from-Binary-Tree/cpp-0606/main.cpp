/// Source : https://leetcode.com/problems/construct-string-from-binary-tree/
/// Author : liuyubobobo
/// Time   : 2021-03-15

#include <iostream>

using namespace std;


/// DFS
/// Time Complexity: O(n)
/// Space Coomplexity: O(h)

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
    string tree2str(TreeNode* t) {

        if(!t) return "";
        string res = to_string(t->val);
        if(!t->left && !t->right) return res;

        res += "(" + tree2str(t->left) + ")";
        if(t->right) res += "(" + tree2str(t->right) + ")";
        return res;
    }
};


int main() {

    return 0;
}
