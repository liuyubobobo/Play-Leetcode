/// Source : https://leetcode.com/problems/validate-binary-search-tree/description/
/// Author : liuyubobobo
/// Time   : 2018-12-16

#include <iostream>
#include <stack>

using namespace std;


/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/// Non-Recursion Solution for Recursion thinking
/// Time Complexity: O(n)
/// Space Complexity: O(h)
class Solution {

public:
    bool isValidBST(TreeNode* root) {

        if(!root) return true;

        stack<TreeNode*> st;
        stack<int> upper, lower;

        st.push(root);
        upper.push(INT_MAX);
        lower.push(INT_MIN);
        while(!st.empty()){
            TreeNode* cur = st.top();
            st.pop();

            int left = lower.top();
            lower.pop();

            int right = upper.top();
            upper.pop();

            if(cur->val > right || cur->val < left)
                return false;

            if(cur->right){
                if(cur->right->val <= cur->val) return false;
                st.push(cur->right);
                lower.push(cur->val + 1);
                upper.push(right);
            }

            if(cur->left){
                if(cur->left->val >= cur->val) return false;
                st.push(cur->left);
                lower.push(left);
                upper.push(cur->val - 1);
            }
        }
        return true;
    }
};


int main() {

    return 0;
}