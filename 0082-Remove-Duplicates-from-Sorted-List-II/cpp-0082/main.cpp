/// Source : https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
/// Author : liuyubobobo
/// Time   : 2019-02-11

#include <iostream>

using namespace std;


/// Linear Scan
/// Time Complexity: O(n)
/// Space Complexity: O(1)

/// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;

        ListNode* prev = dummyHead;
        ListNode* cur = prev->next;
        while(cur){

            int num = 0;
            ListNode* p = cur;
            while(p && p->val == cur->val){
                num ++;
                p = p->next;
            }

            if(num > 1)
                prev->next = p;
            else
                prev = cur;
            cur = p;
        }

        ListNode* ret = dummyHead->next;
        delete dummyHead;
        return ret;
    }
};


int main() {

    return 0;
}