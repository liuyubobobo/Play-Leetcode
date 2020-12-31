/// Source : https://leetcode.com/problems/cousins-in-binary-tree/
/// Author : liuyubobobo
/// Time   : 2019-02-18

#include <iostream>
#include <cassert>
#include <unordered_map>

using namespace std;


/// One-Pass DFS
/// Using HashMap to record the result :-)
///
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

public:
    bool isCousins(TreeNode* root, int x, int y) {

        if(!root || root->val == x || root->val == y)
            return false;

        unordered_map<int, pair<int, int>> record; // depth, parent
        dfs(root, 0, record);

        return record[x].first == record[y].first && record[x].second != record[y].second;
    }

private:
    void dfs(TreeNode* node, int d, unordered_map<int, pair<int, int>>& record){

        if(node->left) {
            record[node->left->val] = make_pair(d + 1, node->val);
            dfs(node->left, d + 1, record);
        }

        if(node->right){
            record[node->right->val] = make_pair(d + 1, node->val);
            dfs(node->right, d + 1, record);
        }
    }
};


int main() {

    return 0;
}