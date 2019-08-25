/// Source : https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/
/// Author : liuyubobobo
/// Time   : 2019-08-25

#include <iostream>
#include <unordered_map>

using namespace std;


/// Using HashMap
/// Time Complexity: O(n)
/// Space Complexity: O(n)

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

        unordered_map<int, ListNode*> map;
        ListNode* cur = dummyHead;
        int presum = 0;
        while(cur){
            presum += cur->val;
            if(map.count(presum))
                map[presum]->next = cur->next;
            else
                map[presum] = cur;
            cur = cur->next;
        }
        return dummyHead->next;
    }
};


int main() {

    return 0;
}