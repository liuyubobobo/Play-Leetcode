/// Source : https://leetcode.com/problems/maximum-width-of-binary-tree/
/// Author : liuyubobobo
/// Time   : 2022-02-27

#include <iostream>
#include <vector>
#include <map>
#include <climits>

using namespace std;


/// DFS
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
    int widthOfBinaryTree(TreeNode* root) {

        int max_depth = get_depth(root);

        vector<unsigned long long> left(max_depth, ULONG_LONG_MAX), right(max_depth,0);
        dfs(root, 0, 0, left, right);

        long long res = 0;
        for(int i = 0; i < max_depth; i ++){
            res = max(res, (long long)(right[i] - left[i] + 1));
        }
        return res;
    }

private:
    void dfs(TreeNode* node, int d, unsigned long long num,
             vector<unsigned long long>& left, vector<unsigned long long>& right){

        if(!node) return;

        left[d] = min(left[d], num);
        right[d] = max(right[d], num);

        dfs(node->left, d + 1, num * 2, left, right);
        dfs(node->right, d + 1, num * 2 + 1, left, right);
    }

    int get_depth(TreeNode* node){

        if(!node) return 0;

        return 1 + max(get_depth(node->left), get_depth(node->right));
    }
};


int main() {

    return 0;
}
