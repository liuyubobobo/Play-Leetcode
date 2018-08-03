/// Source : https://leetcode.com/problems/middle-of-the-linked-list/description/
/// Author : liuyubobobo
/// Time   : 2018-07-28

#include <iostream>

using namespace std;


/// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


/// Two Linear Scans
/// Calculate length and get the answer
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        int len = 0;
        ListNode* cur = head;
        while(cur != NULL)
            len ++, cur = cur->next;

        if(len == 1)
            return head;

        int k = len / 2;
        cur = head;
        for(int i = 0 ; i < k ; i ++)
            cur = cur->next;
        return cur;
    }
};


int main() {

    return 0;
}