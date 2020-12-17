/// Source : https://leetcode.com/problems/plus-one-linked-list/
/// Author : liuyubobobo
/// Time   : 2020-12-16

#include <iostream>


/// Reverse LinkedList and Linear Scan
/// Time Complexity: O(n)
/// Space Complexity: O(n)

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
    ListNode* plusOne(ListNode* head) {

        if(!head) return head;

        head = reverse(head);
        head->val += 1;
        ListNode* cur = head;
        while(cur){
            if(cur->val < 10) break;
            cur->val = 0;
            if(!cur->next) cur->next = new ListNode(1);
            else cur->next->val += 1;

            cur = cur->next;
        }
        return reverse(head);
    }

private:
    ListNode* reverse(ListNode* node){

        if(!node->next) return node;

        ListNode* ret = reverse(node->next);
        node->next->next = node;
        node->next = nullptr;
        return ret;
    }
};


int main() {

    return 0;
}
