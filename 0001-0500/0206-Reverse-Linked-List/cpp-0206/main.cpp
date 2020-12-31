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

// Iterative
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode* pre = NULL;
        ListNode* cur = head;
        while(cur != NULL){
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        return pre;
    }
};

int main() {

    return 0;
}