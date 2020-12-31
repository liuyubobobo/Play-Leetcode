/// Source : https://leetcode.com/problems/find-mode-in-binary-search-tree/
/// Author : liuyubobobo
/// Time   : 2019-07-25

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Using HashMap
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
    unordered_map<int, int> freq;

public:
    vector<int> findMode(TreeNode* root) {

        dfs(root);

        int best = 0;
        vector<int> res;
        for(const pair<int, int>& p: freq)
            if(p.second > best)
                best = p.second, res = {p.first};
            else if(p.second == best)
                res.push_back(p.first);
        return res;
    }

private:
    void dfs(TreeNode* node){

        if(node){
            freq[node->val] ++;
            dfs(node->left);
            dfs(node->right);
        }
    }
};


int main() {

    return 0;
}