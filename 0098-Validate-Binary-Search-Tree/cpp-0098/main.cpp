/// Source : https://leetcode.com/problems/validate-binary-search-tree/description/
/// Author : liuyubobobo
/// Time   : 2018-05-09

#include <iostream>
#include <vector>

using namespace std;

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/// Using inOrder traverse
/// Store all elements in an vector
///
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    bool isValidBST(TreeNode* root) {

        vector<int> vec;
        inOrder(root, vec);
        for(int i = 1 ; i < vec.size() ; i ++)
            if(vec[i-1] >= vec[i])
                return false;
        return true;
    }

private:
    void inOrder(TreeNode* node, vector<int>& vec){

        if(node == NULL)
            return;

        inOrder(node->left, vec);
        vec.push_back(node->val);
        inOrder(node->right, vec);
    }
};

int main() {

    return 0;
}