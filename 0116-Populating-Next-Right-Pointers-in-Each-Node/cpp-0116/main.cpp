/// Source : https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/
/// Author : liuyubobobo
/// Time   : 2018-10-08

#include <iostream>
#include <queue>
#include <cassert>

using namespace std;


/// Using queue for BFS
/// Time Complexity: O(n)
/// Space Compelxity: O(n)

/// Definition for binary tree with next pointer.
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {

        if(!root) return;

        queue<TreeLinkNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            int n = (1 << level);
            while(n --){
                TreeLinkNode* cur = q.front();
                q.pop();
                if(n)
                    cur->next = q.front();
                if(cur->left){
                    q.push(cur->left);
                    assert(cur->right);
                    q.push(cur->right);
                }
            }
            level ++;
        }
    }
};


int main() {

    return 0;
}