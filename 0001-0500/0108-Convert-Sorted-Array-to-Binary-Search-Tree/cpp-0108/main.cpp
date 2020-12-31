/// Source : https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
/// Author : liuyubobobo
/// Time   : 2018-10-30

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

/// Recursion
/// Time Complexity: O(n)
/// Space Complexity: O(logn)
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {

        if(nums.size() == 0)
            return NULL;
        return buildTree(nums, 0, nums.size() - 1);
    }

private:
    TreeNode* buildTree(const vector<int>& nums, int l, int r){

        if(l > r) return NULL;
        if(l == r) return new TreeNode(nums[l]);

        int mid = (l + r) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = buildTree(nums, l, mid - 1);
        root->right = buildTree(nums, mid + 1, r);
        return root;
    }
};


int main() {

    return 0;
}