/// Source : https://leetcode.com/problems/find-distance-in-a-binary-tree/
/// Author : liuyubobobo
/// Time   : 2021-01-28

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/// DFS
/// Time Complexity: O(n)
/// Space Complexity: O(h)

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
    int findDistance(TreeNode* root, int p, int q) {

        vector<int> pv, qv;
        dfs(root, p, pv);
        dfs(root, q, qv);

        assert(pv.back() == p && qv.back() == q);

        int i;
        for(i = 0; i < pv.size() && i < qv.size(); i ++)
            if(pv[i] != qv[i]) break;

        return pv.size() - i + qv.size() - i;
    }

private:
    bool dfs(TreeNode* node, int t, vector<int>& v){

        if(!node) return false;

        v.push_back(node->val);
        if(t == node->val) return true;

        if(dfs(node->left, t, v)) return true;
        if(dfs(node->right, t, v)) return true;

        v.pop_back();
        return false;
    }
};


int main() {

    return 0;
}
