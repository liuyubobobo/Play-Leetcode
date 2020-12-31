/// Source : https://leetcode.com/problems/intersection-of-two-linked-lists/description/
/// Author : liuyubobobo
/// Time   : 2018-10-01

#include <iostream>
#include <unordered_set>

using namespace std;

/// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


/// Two Pointers
/// Time Complexity: O(m + n)
/// Space Complexity: O(1)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        ListNode* pA = headA;
        ListNode* pB = headB;
        while(pA || pB){

            if(pA == pB)
                return pA;

            if(pA) pA = pA->next;
            else pA = headB;

            if(pB) pB = pB->next;
            else pB = headA;
        }

        return NULL;
    }
};


int main() {

    return 0;
}