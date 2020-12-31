/// Source : https://leetcode.com/problems/average-of-levels-in-binary-tree/description/
/// Author : liuyubobobo
/// Time   : 2018-06-03

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/// DFS
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {

        vector<double> res;
        if(root == NULL)
            return res;

        vector<int> count;

        dfs(root, 0, res, count);
        assert(res.size() == count.size());
        for(int i = 0 ; i < res.size() ; i ++)
            res[i] /= count[i];

        return res;
    }

private:
    void dfs(TreeNode* node, int level, vector<double>& res, vector<int>& count){

        if(node == NULL)
            return;

        if(level < res.size()){
            res[level] += (double)node->val;
            assert(level < count.size());
            count[level] += 1;
        }
        else{
            res.push_back((double)node->val);
            count.push_back(1);
            assert(res.size() == count.size());
        }

        dfs(node->left, level + 1, res, count);
        dfs(node->right, level + 1, res, count);
    }
};


int main() {

    return 0;
}