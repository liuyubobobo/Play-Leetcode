/// Source : https://leetcode.com/problems/insufficient-nodes-in-root-to-leaf-paths/
/// Author : liuyubobobo
/// Time   : 2019-06-08

#include <iostream>
#include <unordered_map>
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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {

        unordered_map<TreeNode*, vector<int>> map;
        vector<TreeNode*> path;
        return dfs(root, 0, path, map, limit);
    }

private:
    TreeNode* dfs(TreeNode* node, int cur_sum, vector<TreeNode*>& path,
             unordered_map<TreeNode*, vector<int>>& map, int limit){

        path.push_back(node);
        cur_sum += node->val;

        if(!node->left && !node->right){
            for(TreeNode* t: path)
                map[t].push_back(cur_sum);
        }
        else{
            if(node->left)
                node->left = dfs(node->left, cur_sum, path, map, limit);
            if(node->right)
                node->right = dfs(node->right, cur_sum, path, map, limit);
        }

        path.pop_back();

        if(insufficient(map[node], limit)){
            if(node->left && node->right) assert(false);
            else if(node->left) return node->left;
            else if(node->right) return node->right;
            return NULL;
        }
        return node;
    }

    bool insufficient(const vector<int>& vec, int limit){

        for(int e: vec)
            if(e >= limit) return false;
        return true;
    }
};


int main() {

    return 0;
}