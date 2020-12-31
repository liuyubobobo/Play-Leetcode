/// Source : https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/
/// Author : liuyubobobo
/// Time   : 2019-08-17

#include <iostream>
#include <map>

using namespace std;


/// DFS and Using HashMap
/// Time Complexity: O(n)
/// Space Complexity: O(n)

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

private:
    map<int, int> sum;

public:
    int maxLevelSum(TreeNode* root) {

        dfs(root, 1);
        int res = -1, best = INT_MIN;
        for(const pair<int, int>& p: sum)
            if(p.second > best)
                best = p.second, res = p.first;
        return res;
    }

private:
    void dfs(TreeNode* node, int level){

        if(!node) return;
        sum[level] += node->val;
        dfs(node->left, level + 1);
        dfs(node->right, level + 1);
    }
};


int main() {

    return 0;
}