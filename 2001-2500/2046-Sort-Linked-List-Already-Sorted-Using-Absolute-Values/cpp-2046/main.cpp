/// Source : https://leetcode.com/problems/sort-linked-list-already-sorted-using-absolute-values/
/// Author : liuyubobobo
/// Time   : 2021-10-20

#include <iostream>

using namespace std;


/// Linked List
/// Time Complexity: O(n)
/// Space Complexity: O(1)

/// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortLinkedList(ListNode* head) {

        ListNode* neg_head = nullptr, *neg_tail = nullptr;

        ListNode* dummy = new ListNode(0, head);
        ListNode* cur = dummy;
        while(cur->next){
            if(cur->next->val < 0){
                ListNode* neg_node = cur->next;
                cur->next = neg_node->next;
                neg_node->next = neg_head;
                neg_head = neg_node;
                if(neg_head->next == nullptr) neg_tail = neg_head;
            }
            else cur = cur->next;
        }

        if(!neg_head) return dummy->next;

        neg_tail->next = dummy->next;
        dummy->next = neg_head;
        return dummy->next;
    }
};


int main() {

    return 0;
}
