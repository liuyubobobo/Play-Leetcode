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


/// Two Pointers - fast and slow
/// faster pointer moves two steps a time, and slow pointer moves one step a time.
///
/// faster pointer will meet slow pointer eventually.
/// Simple prove: suppose faster pointer is x steps behind slow pointer
/// if x == 1, then in the next time, fast pointer will meet slow pointer
/// if x > 1, then in the next tme, fast pointer will get one step closer to slow pointer
///           the process continues until faster pointer is just one step behind slow pointer
///           thenm in the next time, they meet together:)
///
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    bool hasCycle(ListNode *head) {

        if(head == NULL)
            return false;

        if(head->next == NULL)
            return false;

        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != slow){
            if(fast->next == NULL)
                return false;
            if(fast->next->next == NULL)
                return false;

            fast = fast->next->next;
            slow = slow->next;
        }

        return true;
    }
};

int main() {

    return 0;
}