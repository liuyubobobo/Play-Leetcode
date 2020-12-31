/// Source : https://leetcode.com/problems/subtree-of-another-tree/description/
/// Author : liuyubobobo
/// Time   : 2018-10-16

#include <iostream>

using namespace std;


/// Using String to represent a binary tree
/// Time Complexity: O(m + n + m * n)
/// Space Complexity: O(m + n)

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {

        string ss = "#";
        getTreeString(s, ss);

        string tt = "#";
        getTreeString(t, tt);

        return ss.find(tt) != string::npos;
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