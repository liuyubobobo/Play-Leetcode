/// Source : https://leetcode.com/problems/binary-tree-cameras/
/// Author : liuyubobobo
/// Time   : 2019-03-18

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/// Greedy
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

private:
    int res;
    unordered_set<TreeNode*> set;

public:
    int minCameraCover(TreeNode* root) {

        res = 0;
        set.clear();
        dfs(root, NULL);
        return res ? res : 1;
    }

private:
    void dfs(TreeNode* root, TreeNode* parent){

        if(!root) return;

        dfs(root->left, root);
        dfs(root->right, root);

        if((!root->left || set.count(root->left)) && (!root->right || set.count(root->right))){
            if(!set.count(root) && !parent) res ++;
            return;
        }

        if((root->left && !set.count(root->left)) ||
           (root->right && !set.count(root->right))) {
            res++;
            if (root->left) set.insert(root->left);
            if (root->right) set.insert(root->right);
            set.insert(root);
            if (parent) set.insert(parent);
        }
        return;
    }
};


int main() {

    TreeNode* root1 = new TreeNode(0);
    root1->left = new TreeNode(0);
    root1->left->left = new TreeNode(0);
    root1->left->right = new TreeNode(0);
    cout << Solution().minCameraCover(root1) << endl;
    // 1


    TreeNode* root2 = new TreeNode(0);
    root2->right = new TreeNode(0);
    root2->right->right = new TreeNode(0);
    root2->right->right->right = new TreeNode(0);
    cout << Solution().minCameraCover(root2) << endl;
    // 2

    TreeNode* root3 = new TreeNode(0);
    root3->left = new TreeNode(0);
    root3->right = new TreeNode(0);
    root3->right->right = new TreeNode(0);
    cout << Solution().minCameraCover(root3) << endl;
    // 2

    return 0;
}