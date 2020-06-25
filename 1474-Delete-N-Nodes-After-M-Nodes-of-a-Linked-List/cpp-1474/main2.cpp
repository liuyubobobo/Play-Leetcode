/// Source : https://leetcode.com/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/
/// Author : liuyubobobo
/// Time   : 2020-06-24

#include <iostream>


/// Non-Recursion
/// Time Complexity: O(n)
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
    ListNode* deleteNodes(ListNode* head, int m, int n) {

        ListNode* prev = head;
        while(prev){
            for(int i = 1; i < m && prev; i ++)
                prev = prev->next;
            if(!prev) break;

            ListNode* prev2 = prev->next;
            for(int i = 1; i < n && prev2; i ++)
                prev2 = prev2->next;
            if(!prev2){
                prev->next = nullptr;
                break;
            }
            prev->next = prev2->next;
            prev = prev2->next;
        }
        return head;
    }
};


int main() {

    return 0;
}
