/// Source : https://leetcode.com/problems/merge-nodes-in-between-zeros/
/// Author : liuyubobobo
/// Time   : 2022-02-19

#include <iostream>
#include <vector>

using namespace std;


/// Linked List
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
    ListNode* mergeNodes(ListNode* head) {

        ListNode* dummy_head = new ListNode(-1);
        ListNode* res_cur = dummy_head;

        int sum = 0;
        for(ListNode* cur = head->next; cur; cur = cur->next){
            if(cur->val == 0){
                res_cur->next = new ListNode(sum);
                res_cur = res_cur->next;
                sum = 0;
            }
            else sum += cur->val;
        }
        return dummy_head->next;
    }
};


int main() {

    return 0;
}
