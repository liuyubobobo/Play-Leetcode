/// Source : https://leetcode.com/problems/design-front-middle-back-queue/
/// Author : liuyubobobo
/// Time   : 2020-11-28

#include <iostream>

using namespace std;


/// Linked List Operation
/// Time Complexity: O(b + |list2|)
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {

        ListNode* dummyHead = new ListNode(-1, list1);

        ListNode* apre, *bpre, *cur = dummyHead;
        for(int i = 0; i <= b + 1; i ++){
            if(i == a) apre = cur;
            if(i == b + 1) bpre = cur;
            cur = cur->next;
        }

        apre->next = list2;

        cur = list2;
        while(cur->next) cur = cur->next;
        cur->next = bpre->next;

        return dummyHead->next;
    }
};

int main() {

    return 0;
}
