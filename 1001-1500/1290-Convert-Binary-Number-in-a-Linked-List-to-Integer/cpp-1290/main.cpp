/// Source : https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
/// Author : liuyubobobo
/// Time   : 2021-12-06

#include <iostream>


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
    int getDecimalValue(ListNode* head) {

        int cur = 0;
        while(head){
            cur = cur * 2 + head->val;
            head = head->next;
        }
        return cur;
    }
};


int main() {

    return 0;
}
