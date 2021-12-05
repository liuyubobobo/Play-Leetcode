/// Source : https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
/// Author : liuyubobobo
/// Time   : 2021-12-04

#include <iostream>
#include <vector>

using namespace std;


/// Two Pass
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
    ListNode* deleteMiddle(ListNode* head) {

        int len = 0;
        ListNode* cur = head;
        while(cur) len ++, cur = cur->next;

        int x = len / 2;
        ListNode* dummy_head = new ListNode(-1, head);
        cur = dummy_head;
        for(int i = 0; i < x; i ++) cur = cur -> next;

        cur->next = cur->next->next;

        return dummy_head->next;
    }
};

int main() {

    return 0;
}
