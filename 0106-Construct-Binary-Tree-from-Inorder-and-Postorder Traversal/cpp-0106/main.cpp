#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }

private:
    TreeNode* buildTree(vector<int>& inorder, int inorderL, int inorderR,
                        vector<int>& postorder, int postorderL, int postorderR){

        if(inorderL >= inorderR){
            assert(postorderL >= postorderR);
            return NULL;
        }

        if(inorderL + 1 == inorderR){
            assert(postorderL + 1 == postorderR);
            return new TreeNode(inorder[inorderL]);
        }

        TreeNode* root = new TreeNode(postorder[postorderR - 1]);
        int rootPos = find(inorder.begin() + inorderL, inorder.begin() + inorderR, root->val) - inorder.begin();
        assert(inorderL <= rootPos && rootPos < inorderR);

        int lsize = rootPos - inorderL;
        int rsize = inorderR - (rootPos + 1);
        root->left = buildTree(inorder, inorderL, inorderL + lsize, postorder, postorderL, postorderL + lsize);
        root->right = buildTree(inorder, rootPos + 1, inorderR, postorder, postorderL + lsize, postorderR - 1);
        return root;
    }
};


int main() {

    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};
    TreeNode* root = Solution().buildTree(inorder, postorder);

    return 0;
}