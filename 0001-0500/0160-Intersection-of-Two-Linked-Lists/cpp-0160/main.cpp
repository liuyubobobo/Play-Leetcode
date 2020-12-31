/// Source : https://leetcode.com/problems/intersection-of-two-linked-lists/description/
/// Author : liuyubobobo
/// Time   : 2018-10-01

#include <iostream>

using namespace std;

/// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


/// Brute Force
/// Time Complexity: O(m*n)
/// Space Complexity: O(1)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        for(ListNode* pA = headA; pA; pA = pA->next)
            for(ListNode* pB = headB; pB; pB = pB->next)
                if(pA == pB)
                    return pA;
        return NULL;
    }
};


int main() {

    return 0;
}