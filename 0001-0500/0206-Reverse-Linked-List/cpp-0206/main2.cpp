/// Source : https://leetcode.com/problems/reverse-linked-list/description/
/// Author : liuyubobobo
/// Time   : 2017-11-15

#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Recursive
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        if(head == NULL || head->next == NULL)
            return head;

        ListNode* rhead = reverseList(head->next);

        head->next->next = head;
        head->next = NULL;

        return rhead;
    }
};

int main() {

    return 0;
}