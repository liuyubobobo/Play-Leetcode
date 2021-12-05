/// Source : https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/
/// Author : liuyubobobo
/// Time   : 2021-12-04

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// LCA
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
public:
    string getDirections(TreeNode* root, int s, int t) {

        root = lca(root, s, t);

        string path1 = "", path2 = "";
        get_path(root, s, path1);
        get_path(root, t, path2);
        return string(path1.size(), 'U') + path2;
    }

private:
    bool get_path(TreeNode* node, int x, string& path){

        if(!node) return false;
        if(node->val == x) return true;

        path += "L";
        if(get_path(node->left, x, path)) return true;

        path.back() = 'R';
        if(get_path(node->right, x, path)) return true;
        path.pop_back();

        return false;
    }

    TreeNode* lca(TreeNode* node, int a, int b){

        if(!node) return nullptr;
        if(node->val == a || node->val == b) return node;

        TreeNode* l = lca(node->left, a, b);
        TreeNode* r = lca(node->right, a, b);
        if(l && r) return node;
        return l ? l : r;
    }
};


int main() {

    TreeNode* left = new TreeNode(1, new TreeNode(3), nullptr);
    TreeNode* right = new TreeNode(2, new TreeNode(6), new TreeNode(4));
    TreeNode* root = new TreeNode(5, left, right);
    cout << Solution().getDirections(root, 3, 6) << endl;
    // UURL

    return 0;
}
