/// Source : https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/
/// Author : liuyubobobo
/// Time   : 2020-05-23

#include <iostream>
#include <unordered_map>

using namespace std;


/// DFS + HashSet
/// Time Complexity: O(n)
/// Space Complexity: O(n + h)

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
    int pseudoPalindromicPaths (TreeNode* root) {

        unordered_map<int, int> freq;
        return dfs(root, freq);
    }

private:
    int dfs(TreeNode* node, unordered_map<int, int>& freq){

        freq[node->val] ++;

        int res = 0;
        if(!node->left && !node->right) res = ok(freq);
        else {
            if (node->left) res += dfs(node->left, freq);
            if (node->right) res += dfs(node->right, freq);
        }

        freq[node->val] --;
        if(freq[node->val] == 0) freq.erase(node->val);

        return res;
    }

    bool ok(unordered_map<int, int>& freq){

        int odd = 0;
        for(const pair<int, int>& p: freq)
            odd += p.second % 2;
        return odd <= 1;
    }
};


int main() {

    return 0;
}
