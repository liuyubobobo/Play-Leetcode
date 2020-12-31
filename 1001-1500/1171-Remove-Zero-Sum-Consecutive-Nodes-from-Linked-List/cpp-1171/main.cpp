/// Source : https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/
/// Author : liuyubobobo
/// Time   : 2020-04-11

#include <iostream>
#include <unordered_map>

using namespace std;


/// Brute Force
/// Time Complexity: O(n^2)
/// Space Complexity: O(1)

/// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {

        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;

        for(ListNode* prev = dummyHead; prev->next;){

            int sum = 0;
            for(ListNode* node = prev->next; node; node = node->next){
                sum += node->val;
                if(sum == 0){
                    prev->next = node->next;
                    break;
                }
            }
            if(sum) prev = prev->next;
        }
        return dummyHead->next;
    }
};


int main() {

    return 0;
}