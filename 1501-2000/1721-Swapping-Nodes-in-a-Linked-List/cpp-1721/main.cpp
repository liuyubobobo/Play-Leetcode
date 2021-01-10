/// Source : https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
/// Author : liuyubobobo
/// Time   : 2021-01-09

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Using HashMap to record index and Node
/// Time Complexity: O(n)
/// Space Complexity: O(n)

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
        unordered_map<int, ListNode*> nodes;
        while(cur){
            nodes[len ++] = cur;
            cur = cur->next;
        }

        int a = k - 1, b = len - k;
        swap(nodes[a], nodes[b]);

        ListNode* dummyHead = new ListNode(-1);
        cur = dummyHead;
        for(int i = 0; i < len; i ++){
            cur->next = nodes[i];
            cur = cur->next;
        }
        cur->next = nullptr;
        return dummyHead->next;
    }
};


int main() {

    return 0;
}
