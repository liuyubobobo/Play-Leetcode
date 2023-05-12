/// Source : https://leetcode.com/problems/split-a-circular-linked-list/description/
/// Author : liuyubobobo
/// Time   : 2023-05-12

#include <iostream>
#include <vector>

using namespace std;


/// Slow and Fast Pointer
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
    vector<ListNode*> splitCircularLinkedList(ListNode* list) {

        ListNode *slow = list, *fast = list->next;
        while(fast->next != list){
            slow = slow->next;
            fast = fast->next;
            if(fast->next == list) break;
            else fast = fast->next;
        }

        ListNode *first = list, *second = slow->next;
        slow->next = first;
        fast->next = second;
        return {first, second};
    }
};


int main() {

    return 0;
}
