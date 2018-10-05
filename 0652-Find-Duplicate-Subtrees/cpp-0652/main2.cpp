/// Source : https://leetcode.com/problems/find-duplicate-subtrees/description/
/// Author : liuyubobobo
/// Time   : 2018-10-05

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Serializae Binary Tree
/// Using another easier hashcode
///
/// Time Complexity: O(n^2)
/// Space Complexity: O(n^2)

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {

        vector<TreeNode*> res;
        unordered_map<string, int> map;
        dfs(root, map, res);
        return res;
    }

private:
    string dfs(TreeNode* root, unordered_map<string, int>& map,
               vector<TreeNode*>& res){

        if(!root)
            return "#";

        string left = dfs(root->left, map, res);
        string right = dfs(root->right, map, res);
        string hashcode = to_string(root->val) + "," + left + "," + right;

        if(map[hashcode] == 1)
            res.push_back(root);
        map[hashcode] ++;
        return hashcode;
    }
};


int main() {

    return 0;
}