/// Source : https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/
/// Author : liuyubobobo
/// Time   : 2018-10-19

#include <iostream>
#include <queue>
#include <cassert>

using namespace std;


/// BFS without queue
/// Since the upper level have already been a linked list
/// We can traverse the upper level in a linked list way to connect the lower level
/// Actually, the upper linked list is our queue :-)
///
/// Time Complexity: O(n)
/// Space Compelxity: O(1)

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

        while(root->left){
            TreeLinkNode* p = root;
            TreeLinkNode* dummyHead = new TreeLinkNode(-1);
            TreeLinkNode* cur = dummyHead;
            while(p){
                cur->next = p->left;
                cur = cur->next;

                cur->next = p->right;
                cur = cur->next;

                p = p->next;
            }

            delete dummyHead;
            root = root->left;
        }
    }
};


int main() {

    return 0;
}