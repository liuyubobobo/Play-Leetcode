/// Source : https://leetcode.com/problems/middle-of-the-linked-list/description/
/// Author : liuyubobobo
/// Time   : 2018-08-02

#include <iostream>

using namespace std;


/// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


/// Fast and Slow Pointers
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        if(head == NULL || head->next == NULL)
            return head;

        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};


int main() {

    return 0;
}