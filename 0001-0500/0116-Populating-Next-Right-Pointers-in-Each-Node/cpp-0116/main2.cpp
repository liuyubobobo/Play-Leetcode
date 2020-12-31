/// Source : https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/
/// Author : liuyubobobo
/// Time   : 2018-10-08

#include <iostream>
#include <queue>
#include <cassert>

using namespace std;


/// DFS
/// Time Complexity: O(n)
/// Space Compelxity: O(logn)

/// Definition for binary tree with next pointer.
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {

public:
    void connect(TreeLinkNode *root) {

        if(!root || !root->left) return;
        dfs(root->left, root->right);

        connect(root->left);
        connect(root->right);
    }

private:
    void dfs(TreeLinkNode* l, TreeLinkNode* r){

        if(l){
            l->next = r;
            dfs(l->right, r->left);
        }
    }
};


int main() {

    return 0;
}