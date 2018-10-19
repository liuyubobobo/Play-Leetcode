/// Source : https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/description/
/// Author : liuyubobobo
/// Time   : 2018-10-18

#include <iostream>
#include <queue>

using namespace std;


/// Since the upper level have already been a linked list
/// We can traverse the upper level in a linked list way to connect the lower level
///
/// Time Complexity: O(n)
/// Space Complexity: O(1)

/// Definition for binary tree with next pointer.
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {

        if(!root)
            return;

        TreeLinkNode* first = root;
        while(first){

            TreeLinkNode* p = first;
            TreeLinkNode* cur = NULL;
            first =NULL;
            while(p){
                if(p->left){
                    if(cur) cur->next = p->left, cur = cur->next;
                    else cur = first = p->left;
                }
                if(p->right){
                    if(cur) cur->next = p->right, cur = cur->next;
                    else cur = first = p->right;
                }
                p = p->next;
            }
        }
    }
};


int main() {

    return 0;
}