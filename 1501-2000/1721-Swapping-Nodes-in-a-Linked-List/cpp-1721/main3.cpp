/// Source : https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
/// Author : liuyubobobo
/// Time   : 2021-01-09

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Single Passes and Swap value
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
    ListNode* swapNodes(ListNode* head, int k) {

        ListNode* cur = head;
        for(int i = 0; i < k - 1; i ++)
            cur = cur->next;
        ListNode* anode = cur;

        ListNode *bnode = head;
        while(cur->next){
            cur = cur->next;
            bnode = bnode->next;
        }
        swap(anode->val, bnode->val);
        return head;
    }
};


int main() {

    return 0;
}
