/// Source : https://leetcode.com/problems/minimum-distance-between-bst-nodes/description/
/// Author : liuyubobobo
/// Time   : 2010-02-11

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

/// Using Array
/// Store All Numbers in an array and sort, then get the min distance
///
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int minDiffInBST(TreeNode* root) {

        vector<int> nums;
        dfs(root, nums);
        sort(nums.begin(), nums.end());

        int res = INT_MAX;
        for(int i = 1 ; i < nums.size() ; i ++)
            res = min(res, nums[i] - nums[i-1]);

        return res;
    }

private:
    void dfs(TreeNode* node, vector<int>& nums){

        if(node == NULL)
            return;

        nums.push_back(node->val);
        dfs(node->left, nums);
        dfs(node->right, nums);
    }
};

int main() {

    // [90,69,null,49,89,null,52,null,null,null,null]

    return 0;
}