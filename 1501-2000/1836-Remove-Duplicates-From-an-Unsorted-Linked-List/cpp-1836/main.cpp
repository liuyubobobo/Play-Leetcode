/// Source : https://leetcode.com/problems/remove-duplicates-from-an-unsorted-linked-list/
/// Author : liuyubobobo
/// Time   : 2021-04-24

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
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {

        ListNode* dummyHead = new ListNode(-1, head);

        unordered_map<int, int> f;
        for(ListNode* cur = head; cur != nullptr; cur = cur->next)
            f[cur->val] ++;

        ListNode* prev = dummyHead;
        while(prev->next){
            if(f[prev->next->val] > 1)
                prev->next = prev->next->next;
            else
                prev = prev->next;
        }
        return dummyHead->next;
    }
};


int main() {

    return 0;
}
