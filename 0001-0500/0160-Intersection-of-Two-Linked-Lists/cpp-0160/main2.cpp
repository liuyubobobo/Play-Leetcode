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


/// Using HashSet
/// Time Complexity: O(m + n)
/// Space Complexity: O(m)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        unordered_set<ListNode*> set;
        for(ListNode* pA = headA; pA; pA = pA->next)
            set.insert(pA);

        for(ListNode* pB = headB; pB; pB = pB->next)
            if(set.count(pB))
                return pB;

        return NULL;
    }
};


int main() {

    return 0;
}