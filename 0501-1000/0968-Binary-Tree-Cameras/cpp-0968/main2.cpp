/// Source : https://leetcode.com/problems/binary-tree-cameras/
/// Author : liuyubobobo
/// Time   : 2019-03-17

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/// Memory Search - Tree DP
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

public:
    int minCameraCover(TreeNode* root) {

        if(!root) return 0;
        // isCamera, needToeCover - 00, 01, 10, 11
        vector<int> res = dfs(root);
        return res[0 * 2 + 1];
    }

private:
    vector<int> dfs(TreeNode* root){

        if(!root) return {0, 0, 0, 0};

        vector<int> lres = dfs(root->left);
        vector<int> rres = dfs(root->right);

        vector<int> res(4);
        // 10 and 11
        res[1 * 2 + 0] = res[1 * 2 + 1] = lres[0 * 2 + 0] + rres[0 * 2 + 0];

        // 00 and 01
        res[0 * 2 + 0] = res[0 * 2 + 1] = 1 + lres[0 * 2 + 0] + rres[0 * 2 + 0];

        // 00
        res[0 * 2 + 0] = min(res[0 * 2 + 0], lres[0 * 2 + 1] + rres[0 * 2 + 1]);

        // 01
        if(root->left)
            res[0 * 2 + 1] = min(res[0 * 2 + 1], 1 + lres[1 * 2 + 0] + rres[0 * 2 + 1]);
        if(root->right)
            res[0 * 2 + 1] = min(res[0 * 2 + 1], 1 + lres[0 * 2 + 1] + rres[1 * 2 + 0]);
        if(root->left && root->right)
            res[0 * 2 + 1] = min(res[0 * 2 + 1], 2 + lres[1 * 2 + 0] + rres[1 * 2 + 0]);

        return res;
    }
};


int main() {

    TreeNode* root1 = new TreeNode(0);
    root1->left = new TreeNode(0);
    root1->left->left = new TreeNode(0);
    root1->left->right = new TreeNode(0);
    cout << Solution().minCameraCover(root1) << endl;

    return 0;
}