/// Source : https://leetcode.com/problems/flip-equivalent-binary-trees/
/// Author : liuyubobobo
/// Time   : 2018-12-01

#include <iostream>
#include <vector>

using namespace std;


/// Canonical Traversal
/// Time Complexity: O(N1 + N2)
/// Space Complexity: O(N1 + N2)

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {

        vector<int> vec1, vec2;

        dfs(root1, vec1);
//        for(TreeNode* node: vec1)
//            cout << (node ? node->val : -1) << " ";
//        cout << endl;

        dfs(root2, vec2);
//        for(TreeNode* node: vec2)
//            cout << (node ? node->val : -1) << " ";
//        cout << endl;

        return vec1 == vec2;
    }

private:
    void dfs(TreeNode* node, vector<int>& vec){

        vec.push_back(node ? node->val : -1);
        if(!node)
            return;

        int L = node->left ? node->left->val : -1;
        int R = node->right ? node->right->val : -1;
        if(L <= R)
            dfs(node->left, vec), dfs(node->right, vec);
        else
            dfs(node->right, vec), dfs(node->left, vec);
    }
};


int main() {

    cout << Solution().flipEquiv(NULL, new TreeNode(1)) << endl;
    // False

    return 0;
}