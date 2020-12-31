/// Source : https://leetcode.com/problems/same-tree/description/
/// Author : liuyubobobo
/// Time   : 2018-10-16

#include <iostream>

using namespace std;


/// Using a string to represent a Binary Tree in preorder
/// Time Complexity: O(n)
/// Space Complexity: O(h)

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        string ps = "#";
        getTreeString(p, ps);

        string qs = "#";
        getTreeString(q, qs);

        return ps == qs;
    }

private:
    void getTreeString(TreeNode* node, string& s){

        if(!node){
            s += "NULL#";
            return;
        }

        s += to_string(node->val) + "#";
        getTreeString(node->left, s);
        getTreeString(node->right, s);
    }
};


int main() {

    return 0;
}