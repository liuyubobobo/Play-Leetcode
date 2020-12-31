/// Source : https://leetcode.com/problems/reverse-linked-list-ii/description/
/// Author : liuyubobobo
/// Time   : 2019-01-10

#include <iostream>

using namespace std;


/// Non-Recursive
/// Time Complexity: O(n)
/// Space Complexity: O(n)

/// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {

        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;

        ListNode* pre = dummyHead;
        for(int i = 0; i < m - 1; i ++, pre = pre->next);

        ListNode* tail = pre->next;
        ListNode* left = tail;
        pre->next = reverse(pre->next, n - m, left);
        if(left != tail) tail->next = left;

        ListNode* ret = dummyHead->next;
        delete dummyHead;
        return ret;
    }

private:
    ListNode* reverse(ListNode* head, int n, ListNode* &left){

        if(!head || !head->next || !n)
            return head;

        ListNode* pre = head, *cur = head->next;
        while(n -- ){
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        };
        left = cur;
        return pre;
    }
};


int main() {

    return 0;
}