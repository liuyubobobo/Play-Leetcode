/// Source : https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/
/// Author : liuyubobobo
/// Time   : 2018-04-22

#include <iostream>

using namespace std;


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


/// Recursive
/// Time Complexity: O(nlogn)
/// Space Complexity: O(logn)
class Solution {

public:
    TreeNode* sortedListToBST(ListNode* head) {

        if(head == NULL)
            return NULL;

        int len = getLen(head);
        return buildBST(head, 0, len - 1);
    }

private:
    TreeNode* buildBST(ListNode* head, int l, int r){

        if(l > r)
            return NULL;

        if(l == r)
            return new TreeNode(head->val);

        int mid = l + (r - l + 1) / 2;
        ListNode* cur = head;
        for(int i = l ; i < mid - 1 ; i ++)
            cur = cur->next;

        ListNode* node = cur->next;
        cur->next = NULL;

        TreeNode* root = new TreeNode(node->val);
        root->left = buildBST(head, l, mid - 1);
        root->right = buildBST(node->next, mid + 1, r);
        return root;
    }

    int getLen(ListNode* head){

        ListNode* cur = head;
        int res = 0;
        while(cur != NULL){
            res ++;
            cur = cur->next;
        }
        return res;
    }
};


/// Test Helper
ListNode* createLinkedList(int arr[], int n){

    if(n == 0)
        return NULL;

    ListNode* head = new ListNode(arr[0]);
    ListNode* curNode = head;
    for(int i = 1 ; i < n ; i ++){
        curNode->next = new ListNode(arr[i]);
        curNode = curNode->next;
    }

    return head;
}

void inOrder(TreeNode* node){

    if(node == NULL)
        return;

    inOrder(node->left);
    cout << node->val << " ";
    inOrder(node->right);
}


int main() {

    int arr1[] = {-10, -3, 0, 5, 9};
    ListNode* head1 = createLinkedList(arr1, 5);
    inOrder(Solution().sortedListToBST(head1));
    cout << endl;

    return 0;
}