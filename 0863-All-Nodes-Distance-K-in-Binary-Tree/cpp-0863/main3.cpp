/// Source : https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/
/// Author : liuyubobobo
/// Time   : 2018-07-01

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <queue>

using namespace std;

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/// DFS and get the results during the recursion
///
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {

        if(K == 0)
            return {target->val};

        vector<int> res;
        assert(dfs(root, target, K, res) != -1);
        return res;
    }

private:
    int dfs(TreeNode* root, TreeNode* target, int K, vector<int>& res){

        if(root == NULL)
            return -1;

        if(root == target){
            addRes(root, K, res);
            return 0;
        }

        int L = dfs(root->left, target, K, res);
        if(L != -1){
            if(L + 1 == K)
                addRes(root, 0, res);
            else
                addRes(root->right, K - L - 2, res);
            return L + 1;
        }

        int R = dfs(root->right, target, K, res);
        if(R != -1){
            if(R + 1 == K)
                addRes(root, 0, res);
            else
                addRes(root->left, K - R - 2, res);
            return R + 1;
        }

        return -1;
    }

    void addRes(TreeNode* root, int dis, vector<int>& res){

        if(root == NULL)
            return;

        if(dis == 0){
            res.push_back(root->val);
            return;
        }

        addRes(root->left, dis - 1, res);
        addRes(root->right, dis - 1, res);
    }
};


int main() {

    return 0;
}