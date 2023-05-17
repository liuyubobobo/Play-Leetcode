/// Source : https://leetcode.com/problems/extract-kth-character-from-the-rope-tree/description/
/// Author : liuyubobobo
/// Time   : 2023-05-17

#include <iostream>
#include <vector>

using namespace std;


/// DFS
/// Time Complexity: O(n)
/// Space Complexity: O(n)

/// Definition for a rope tree node.
struct RopeTreeNode {
    int len;
    string val;
    RopeTreeNode *left;
    RopeTreeNode *right;
    RopeTreeNode() : len(0), val(""), left(nullptr), right(nullptr) {}
    RopeTreeNode(string s) : len(0), val(std::move(s)), left(nullptr), right(nullptr) {}
    RopeTreeNode(int x) : len(x), val(""), left(nullptr), right(nullptr) {}
    RopeTreeNode(int x, RopeTreeNode *left, RopeTreeNode *right) : len(x), val(""), left(left), right(right) {}
};

class Solution {
public:
    char getKthCharacter(RopeTreeNode* root, int k) {

        return dfs(root, k);
    }

private:
    char dfs(RopeTreeNode* node, int k) {

        if(node->len == 0) return node->val[k - 1];

        int left_len = node->left ? (node->left->len ? node->left->len : node->left->val.size()) : 0;
        if(k <= left_len) return dfs(node->left, k);
        return dfs(node->right, k - left_len);
    }
};


int main() {

    return 0;
}
