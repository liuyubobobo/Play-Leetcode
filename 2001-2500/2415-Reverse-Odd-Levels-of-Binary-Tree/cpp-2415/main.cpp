/// Source : https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/
/// Author : liuyubobobo
/// Time   : 2022-09-20

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/// DFS
/// Time Complexity: O(n)
/// Space Complexity: O(n)

///Definition for a binary tree node.
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
    TreeNode* reverseOddLevels(TreeNode* root) {

        vector<vector<TreeNode*>> levels;
        dfs(root, 0, levels);

        for(vector<TreeNode*>& level: levels){
            for(int i = 0, j = level.size() - 1; i < j; i ++, j --)
                swap(level[i]->val, level[j]->val);
        }
        return root;
    }

private:
    void dfs(TreeNode* node, int d, vector<vector<TreeNode*>>& levels){

        if(!node) return;

        if(d & 1){
            int index = (d - 1) / 2;
            if(index >= levels.size()){
                assert(index == levels.size());
                levels.push_back({node});
            }
            else levels[index].push_back(node);
        }

        dfs(node->left, d + 1, levels);
        dfs(node->right, d + 1, levels);
    }
};


int main() {

    return 0;
}
