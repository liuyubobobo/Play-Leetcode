/// Source : https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/
/// Author : liuyubobobo
/// Time   : 2019-04-13

#include <iostream>

using namespace std;


/// Recusion
/// Time Complexity: O(n)
/// Space Complexity: O(h)

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

public:
    int maxAncestorDiff(TreeNode* root) {

        int maxv, minv;
        return dfs(root, maxv, minv);
    }

    int dfs(TreeNode* node, int& maxv, int& minv){

        maxv = node->val;
        minv = node->val;
//        cout << "in " << node->val << endl;

        int res = 0;
        if(node->left){
            int lmaxv, lminv;
            int lres = dfs(node->left, lmaxv, lminv);

            res = max(res, lres);
            res = max(res, abs(node->val - lmaxv));
            res = max(res, abs(node->val - lminv));
//            cout << "after search left : " << res << endl;

            maxv = max(maxv, lmaxv);
            minv = min(minv, lminv);
        }

        if(node->right){
            int rmaxv, rminv;
            int rres = dfs(node->right, rmaxv, rminv);

            res = max(res, rres);
            res = max(res, abs(node->val - rmaxv));
            res = max(res, abs(node->val - rminv));
//            cout << "after search right : " << res << endl;

            maxv = max(maxv, rmaxv);
            minv = min(minv, rminv);
        }

        return res;
    }
};


int main() {

    return 0;
}