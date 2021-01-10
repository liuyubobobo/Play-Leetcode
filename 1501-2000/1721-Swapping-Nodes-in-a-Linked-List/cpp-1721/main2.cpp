/// Source : https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
/// Author : liuyubobobo
/// Time   : 2021-01-09

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Two Passes and Swap value
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

        int len = 0;
        ListNode* cur = head;
        while(cur)
            cur = cur->next, len ++;

        int a = k - 1, b = len - k;

        ListNode *anode = nullptr, *bnode = nullptr;
        cur = head;
        for(int i = 0; i < len; i ++){
            if(i == a) anode = cur;
            if(i == b) bnode = cur;
            cur = cur->next;
        }
        swap(anode->val, bnode->val);
        return head;
    }
};


int main() {

    return 0;
}
