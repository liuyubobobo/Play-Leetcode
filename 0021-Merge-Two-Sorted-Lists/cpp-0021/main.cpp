/// Source : https://leetcode.com/problems/merge-two-sorted-lists/description/
/// Author : liuyubobobo
/// Time   : 2017-12-01

#include <iostream>

using namespace std;

/// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/// Iterative
/// Time Complexity: O(len(l1) + len(l2))
/// Space Complexity: O(1)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        ListNode* dummyHead = new ListNode(-1);
        ListNode* p = dummyHead;
        ListNode* l1p = l1;
        ListNode* l2p = l2;
        while(l1p != NULL && l2p != NULL){
            if(l1p->val < l2p->val){
                p->next = l1p;
                l1p = l1p->next;
            }
            else{
                p->next = l2p;
                l2p = l2p->next;
            }

            p = p->next;
        }

        if(l1p != NULL)
            p->next = l1p;
        else
            p->next = l2p;

        ListNode* ret = dummyHead->next;
        dummyHead->next = NULL;
        delete dummyHead;

        return ret;
    }
};

int main() {

    return 0;
}