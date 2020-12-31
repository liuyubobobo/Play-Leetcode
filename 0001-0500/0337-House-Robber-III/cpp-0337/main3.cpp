/// Source : https://leetcode.com/problems/house-robber-iii/description/
/// Author : liuyubobobo
/// Time   : 2017-12-09

#include <iostream>
#include <vector>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/// Redefine the recursive function and return a two-element array
/// represent the include and exclude maximum result for robbing the node
///
/// Time Complexity: O(n), where n is the nodes' number in the tree
/// Space Complexity: O(1)
class Solution {

public:
    int rob(TreeNode* root) {
        vector<int> result = tryRob(root);
        return max(result[0], result[1]);
    }

private:
    vector<int> tryRob(TreeNode* root){

        if(root == NULL)
            return vector<int>(2, 0);

        vector<int> resultL = tryRob(root->left);
        vector<int> resultR = tryRob(root->right);
        vector<int> res(2, 0);

        res[0] = resultL[1] + resultR[1];
        res[1] = max(res[0], root->val + resultL[0] + resultR[0]);

        return res;
    }
};

int main() {

    return 0;
}