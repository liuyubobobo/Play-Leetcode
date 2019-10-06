/// Source : https://leetcode.com/problems/two-sum-bsts/
/// Author : liuyubobobo
/// Time   : 2019-10-06

#include <iostream>
#include <set>

using namespace std;


/// DFS and store every value in Set
/// Time Complexity: O(|root1| + |root2|)
/// Space Complexity: O(|root1| + |root2|)

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

        set<int> set1, set2;
        if(root1) dfs(root1, set1);
        if(root2) dfs(root2, set2);

        for(int e: set1) if(set2.count(target - e)) return true;
        return false;
    }

private:
    void dfs(TreeNode* root, set<int>& set){

        set.insert(root->val);
        if(root->left) dfs(root->left, set);
        if(root->right) dfs(root->right, set);
    }
};


int main() {

    return 0;
}