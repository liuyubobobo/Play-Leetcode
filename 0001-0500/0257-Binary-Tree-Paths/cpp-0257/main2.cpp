/// Source : https://leetcode.com/problems/binary-tree-paths/description/
/// Author : liuyubobobo
/// Time   : 2020-10-20

#include <iostream>
#include <string>
#include <vector>

using namespace std;


/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/// Recursive
/// Time Complexity: O(n), where n is the node's number in the tree
/// Space Complexity: O(h), where h is the height of the tree
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {

        if(root == nullptr) return {};

        vector<TreeNode*> path;
        vector<string> res;
        dfs(root, path, res);
        return res;
    }

private:
    void dfs(TreeNode* node, vector<TreeNode*>& path, vector<string>& res){

        path.push_back(node);
        if(node->left == nullptr && node->right == nullptr){
            string str = to_string(path[0]->val);
            for(int i = 1; i < path.size(); i ++)
                str += "->" + to_string(path[i]->val);
            res.push_back(str);
        }

        if(node->left) dfs(node->left, path, res);
        if(node->right) dfs(node->right, path, res);

        path.pop_back();
    }
};


int main() {

    return 0;
}