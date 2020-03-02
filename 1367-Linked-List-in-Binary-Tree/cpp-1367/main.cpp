/// Source : https://leetcode.com/problems/linked-list-in-binary-tree/
/// Author : liuyubobobo
/// Time   : 2020-02-29

#include <iostream>

using namespace std;


/// Recursion
/// Time Complexity: O(treenodes * listnodes)
/// Space Compelxity: O(h)

/// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {

        return go(root, head);
    }

private:
    bool go(TreeNode* node, ListNode* head){

        if(ok(node, head)) return true;

        if(node->left && go(node->left, head)) return true;
        if(node->right && go(node->right, head)) return true;
        return false;
    }

    bool ok(TreeNode* node, ListNode* head){

        if(!head) return true;
        if(!node) return false;
        if(node->val != head->val) return false;
        if(!head->next) return true;

        if(node->left && ok(node->left, head->next)) return true;
        if(node->right && ok(node->right, head->next)) return true;
        return false;
    }
};


int main() {

    return 0;
}
