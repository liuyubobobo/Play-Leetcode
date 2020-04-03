/// Source : https://leetcode.com/problems/remove-duplicates-from-sorted-list/
/// Author : liuyubobobo
/// Time   : 2020-04-02

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

        ListNode* cur = head;
        while(cur && cur->next){
            if(cur->val == cur->next->val) cur->next = cur->next->next;
            else cur = cur->next;
        }
        return head;
    }
};


int main() {

    return 0;
}
