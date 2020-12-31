/// Source : https://leetcode.com/problems/same-tree/description/
/// Author : liuyubobobo
/// Time   : 2019-03-11

#include <iostream>
#include <stack>

using namespace std;


/// Iterative
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
    bool isSameTree(TreeNode* p, TreeNode* q) {

        stack<TreeNode*> stack1, stack2;
        stack1.push(p), stack2.push(q);
        while(!stack1.empty() || !stack2.empty()){
            TreeNode* cur1 = stack1.top();
            stack1.pop();

            TreeNode* cur2 = stack2.top();
            stack2.pop();

            if(cur1 && !cur2) return false;
            if(!cur1 && cur2) return false;
            if(!cur1 && !cur2) continue;

            if(cur1->val != cur2->val) return false;
            stack1.push(cur1->right);
            stack1.push(cur1->left);
            stack2.push(cur2->right);
            stack2.push(cur2->left);
        }

        return stack1.empty() && stack2.empty();
    }
};


int main() {

    return 0;
}