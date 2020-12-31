/// Source : https://leetcode.com/problems/complete-binary-tree-inserter/description/
/// Author : liuyubobobo
/// Time   : 2018-10-07

#include <iostream>
#include <queue>
#include <cassert>

using namespace std;


/// Using queue
/// Time Complexity: init: O(n)
///                  insert: O(1)
///                  get_root: O(1)
/// Space Complexity: O(n)

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class CBTInserter {

private:
    queue<TreeNode*> q;
    TreeNode* root;

public:
    CBTInserter(TreeNode* root) {
        this->root = root;
        q.push(this->root);
        while(true){
            TreeNode* cur = q.front();
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
            if(cur->left && cur->right)
                q.pop();
            else
                break;
        }
    }

    int insert(int v) {

        TreeNode* cur = q.front();
        if(!cur->left){
            cur->left = new TreeNode(v);
            q.push(cur->left);
        }
        else{
            assert(!cur->right);
            cur->right = new TreeNode(v);
            q.push(cur->right);
            q.pop();
        }
        return cur->val;
    }

    TreeNode* get_root() {
        return root;
    }
};


int main() {

    return 0;
}