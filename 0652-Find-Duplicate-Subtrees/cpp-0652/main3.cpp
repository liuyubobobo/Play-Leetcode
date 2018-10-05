/// Source : https://leetcode.com/problems/find-duplicate-subtrees/description/
/// Author : liuyubobobo
/// Time   : 2018-10-05

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Serializae Binary Tree
/// Using global id key to mark each subtree
///
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
    int id = 1;

public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {

        id = 1;
        vector<TreeNode*> res;
        unordered_map<string, int> map;
        unordered_map<int, int> freq;
        dfs(root, map, freq, res);
        return res;
    }

private:
    int dfs(TreeNode* root, unordered_map<string, int>& map,
            unordered_map<int, int>& freq, vector<TreeNode*>& res){

        if(!root)
            return 0;

        int lid = dfs(root->left, map, freq, res);
        int rid = dfs(root->right, map, freq, res);

        string hashcode = to_string(lid) + "#" + to_string(root->val) + "#" + to_string(rid);
        if(!map.count(hashcode))
            map[hashcode] = id ++;

        int rootID = map[hashcode];
        if(freq[rootID] == 1)
            res.push_back(root);
        freq[rootID] ++;
        return rootID;
    }
};


int main() {

    return 0;
}