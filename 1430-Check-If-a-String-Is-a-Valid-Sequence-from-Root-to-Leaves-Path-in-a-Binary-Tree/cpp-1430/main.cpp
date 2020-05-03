/// Source : https://leetcode.com/problems/check-if-a-string-is-a-valid-sequence-from-root-to-leaves-path-in-a-binary-tree/
/// Author : liuyubobobo
/// Time   : 2020-05-02

#include <iostream>
#include <vector>

using namespace std;


/// DFS
/// Time Complexity: O(n)
/// Space Complexity: O(|num|)

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
    bool isValidSequence(TreeNode* root, vector<int>& arr) {

        if(!root) return false;
        if(root->val != arr[0]) return false;
        return ok(root, arr, 0);
    }

private:
    bool ok(TreeNode* node, vector<int>& arr, int index){

        if(index + 1 == arr.size()) return !node->left && !node->right;
        if(node->left && node->left->val == arr[index + 1] &&
           ok(node->left, arr, index + 1)) return true;
        if(node->right && node->right->val == arr[index + 1] &&
           ok(node->right, arr, index + 1)) return true;
        return false;
    }
};


int main() {

    return 0;
}
