/// Source : https://leetcode.com/problems/all-elements-in-two-binary-search-trees/
/// Author : liuyubobobo
/// Time   : 2020-01-11

#include <iostream>
#include <vector>

using namespace std;


/// DFS and Sorting
/// Time Complexity: O(m + n + (m + n)log(m + n))
/// Space Complexity: O(m + n)

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

private:
    vector<int> res;

public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {

        res.clear();
        dfs(root1);
        dfs(root2);
        sort(res.begin(), res.end());
        return res;
    }

private:
    void dfs(TreeNode* node){

        if(!node) return;
        res.push_back(node->val);
        dfs(node->left);
        dfs(node->right);
    }
};


int main() {

    return 0;
}
