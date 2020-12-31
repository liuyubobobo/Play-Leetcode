/// Source : https://leetcode.com/problems/check-completeness-of-a-binary-tree/
/// Author : liuyubobobo
/// Time   : 2018-12-15

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// BFS
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
public:
    bool isCompleteTree(TreeNode* root) {

        if(!root) return true;

        queue<pair<TreeNode*, int>> queue;
        queue.push(make_pair(root, 1));
        int max_index = -1, sz = 0;
        while(!queue.empty()){
            TreeNode* node = queue.front().first;
            int index = queue.front().second;
            queue.pop();

            sz ++;
            max_index = max(max_index, index);

            if(node->left)
                queue.push(make_pair(node->left, 2 * index));
            if(node->right)
                queue.push(make_pair(node->right, 2 * index + 1));
        }
        return sz == max_index;
    }
};


int main() {

    return 0;
}