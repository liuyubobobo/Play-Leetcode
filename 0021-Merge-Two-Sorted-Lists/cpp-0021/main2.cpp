/// Source : https://leetcode.com/problems/merge-two-sorted-lists/description/
/// Author : liuyubobobo
/// Time   : 2017-12-01

#include <iostream>

using namespace std;

/// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/// Recursive
/// Time Complexity: O(len(l1) + len(l2))
/// Space Complexity: O(len(l1) + len(l2))
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        if(l1 == NULL)
            return l2;

        if(l2 == NULL)
            return l1;

        if(l1->val < l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }


        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
};

int main() {

    return 0;
}