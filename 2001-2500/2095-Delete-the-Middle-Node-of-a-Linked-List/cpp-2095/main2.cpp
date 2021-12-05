/// Source : https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
/// Author : liuyubobobo
/// Time   : 2021-12-04

#include <iostream>
#include <vector>

using namespace std;


/// One Pass
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

        ListNode* dummy_head = new ListNode(-1, head);
        ListNode* fast = head, *slow = dummy_head;

        while(fast && fast->next){
            fast = fast->next;
            if(fast) fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;

        return dummy_head->next;
    }
};

int main() {

    return 0;
}
