/// Source : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
/// Author : liuyubobobo
/// Time   : 2020-04-22

#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

/// Binary Lifting
/// Time Complexity: init: O(nlogn)
///                  query: O(logn)
/// Space Complexity: O(nlogn)

///Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

private:
    map<TreeNode*, int> tin, tout;
    map<TreeNode*, TreeNode*> parents;
    vector<TreeNode*> nodes;
    map<TreeNode*, vector<TreeNode*>> up;

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        int time = 0;

        int depth = dfs(root, root, time);

        if(isAncestor(p, q)) return p;
        if(isAncestor(q, p)) return q;

        // up
        for(TreeNode* node: nodes)
            up[node].push_back(parents[node]);

        int d = ceil(log2(depth));
        for(int i = 1; i <= d; i ++)
            for(TreeNode* node: nodes)
                up[node].push_back(up[up[node][i - 1]][i - 1]);

        // lca
        for(int i = d; i >= 0; i --)
            if(!isAncestor(up[p][i], q))
                p = up[p][i];
        return up[p][0];
    }

private:
    // a is x's ancestor?
    bool isAncestor(TreeNode* a, TreeNode* x){
        return tin[a] <= tin[x] && tout[a] >= tout[x];
    }

    int dfs(TreeNode* node, TreeNode* p, int& time){

        if(!node) return 0;

        nodes.push_back(node);
        parents[node] = p;

        int depth = 0;

        tin[node] = time ++;
        depth = max(depth, 1 + dfs(node->left, node, time));
        depth = max(depth, 1 + dfs(node->right, node, time));
        tout[node] = time ++;

        return depth;
    }
};


int main() {

//    [-1,0,3,-2,4,null,null,8]
//    8
//    4
//    Expected: 0

    return 0;
}