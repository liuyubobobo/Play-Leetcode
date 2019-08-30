/// Source : https://leetcode.com/problems/reorder-list/
/// Author : liuyubobobo
/// Time   : 2019-08-30

#include <iostream>

using namespace std;


/// Simulations
/// Time Complexity: O(n)
/// Space Complexity: O(1)


/// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    void reorderList(ListNode* head) {

        if(!head || !head->next) return;

        ListNode* slow = head, *fast = head;
        while(fast->next && fast->next->next)
            slow = slow->next, fast = fast->next, fast = fast->next;

        ListNode* head1 = head, *head2 = slow->next;
        slow->next = NULL;
        head2 = reverse(head2);

        ListNode* dummyHead = new ListNode(-1);
        ListNode* cur= dummyHead, *cur1 = head1, *cur2 = head2;
        for(int i = 0; cur1 || cur2; i ++)
            if(i % 2 == 0) cur->next = cur1, cur = cur->next, cur1 = cur1->next;
            else cur->next = cur2, cur = cur->next, cur2 = cur2->next;
        head = dummyHead->next;
    }

private:
    ListNode* reverse(ListNode* node){

        if(!node->next) return node;
        ListNode* ret = reverse(node->next);
        node->next->next = node;
        node->next = NULL;
        return ret;
    }
};


int main() {

    return 0;
}