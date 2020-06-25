/// Source : https://leetcode.com/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/
/// Author : liuyubobobo
/// Time   : 2020-06-24

#include <iostream>


/// Recursion
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
    ListNode* deleteNodes(ListNode* head, int m, int n) {

        if(!head) return head;

        ListNode* prev = head;
        for(int i = 1; i < m && prev; i ++)
            prev = prev->next;
        if(!prev) return head;

        ListNode* prev2 = prev->next;
        for(int i = 1; i < n && prev2; i ++)
            prev2 = prev2->next;
        if(!prev2){
            prev->next = nullptr;
            return head;
        }

        prev->next = deleteNodes(prev2->next, m, n);
        return head;
    }
};


int main() {

    return 0;
}
