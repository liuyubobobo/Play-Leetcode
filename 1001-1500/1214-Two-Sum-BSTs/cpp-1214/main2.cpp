/// Source : https://leetcode.com/problems/two-sum-bsts/
/// Author : liuyubobobo
/// Time   : 2019-10-06

#include <iostream>
#include <set>

using namespace std;


/// DFS in root1 and search in root 2
/// Time Complexity: O(|root1|log|root2|)
/// Space Complexity: O(|h1| + |h2|)

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {

        if(!root1) return false;
        if(search(root2, target - root1->val)) return true;
        if(twoSumBSTs(root1->left, root2, target)) return true;
        if(twoSumBSTs(root1->right, root2, target)) return true;
        return false;
    }

private:
    bool search(TreeNode* root, int num){

        if(!root) return false;
        if(root->val == num) return true;
        else if(num < root->val) return search(root->left, num);
        return search(root->right, num);
    }
};


int main() {

    return 0;
}