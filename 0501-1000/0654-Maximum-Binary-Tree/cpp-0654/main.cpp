/// Source : https://leetcode.com/problems/maximum-binary-tree/
/// Author : liuyubobobo
/// Time   : 2022-08-19

#include <iostream>
#include <vector>

using namespace std;


/// DFS
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {

        int n = nums.size();
        return construct(nums, 0, n - 1);
    }

private:
    TreeNode* construct(const vector<int>& nums, int l, int r){

        if(l > r) return nullptr;

        int max_index = max_element(nums.begin() + l, nums.begin() + (r + 1)) - nums.begin();
        TreeNode* ret = new TreeNode(nums[max_index]);
        ret->left = construct(nums, l, max_index - 1);
        ret->right = construct(nums, max_index + 1, r);
        return ret;
    }
};


int main() {

    return 0;
}
