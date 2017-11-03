/// Source : https://leetcode.com/problems/linked-list-cycle/description/
/// Author : liuyubobobo
/// Time   : 2017-11-02

#include <iostream>
#include <unordered_set>

using namespace std;

/// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


/// Using Hash Table
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    bool hasCycle(ListNode *head) {

        if(head == NULL)
            return false;

        // Use long long type for 64-bit os
        unordered_set<long long> node_address;

        ListNode* p = head;
        while(p != NULL){
            if(node_address.find((long long)(p)) == node_address.end())
                node_address.insert((long long)(p));
            else
                return true;

            p = p->next;
        }

        return false;
    }
};

int main() {

    return 0;
}