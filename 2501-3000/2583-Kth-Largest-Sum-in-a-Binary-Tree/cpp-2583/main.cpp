/// Source : https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/description/
/// Author : liuyubobobo
/// Time   : 2023-03-04

#include <iostream>
#include <vector>

using namespace std;


/// DFS
/// Time Complexity: O(n)
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
    long long kthLargestLevelSum(TreeNode* root, int k) {

        vector<long long> sums;
        dfs(root, 0, sums);
        sort(sums.begin(), sums.end(), greater<>());
        return k - 1 < sums.size() ? sums[k - 1] : -1;
    }

private:
    void dfs(TreeNode* root, int level, vector<long long>& sums) {

        if (!root) return;

        if (level >= sums.size()){
            assert(level == sums.size());
            sums.push_back(root->val);
        }
        else sums[level] += root->val;

        dfs(root->left, level + 1, sums);
        dfs(root->right, level + 1, sums);
    }
};


int main() {

    return 0;
}
