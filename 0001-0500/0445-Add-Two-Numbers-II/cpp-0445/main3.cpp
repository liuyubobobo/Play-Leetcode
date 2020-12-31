/// Source : https://leetcode.com/problems/add-two-numbers-ii/
/// Author : liuyubobobo
/// Time   : 2019-09-21

#include <iostream>
#include <stack>

using namespace std;


/// Recursion
/// Time Complexity: O(m + n + max(m, n))
/// Space Complexity: O(max(m, n))

/// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int len1 = get_length(l1), len2 = get_length(l2);
        int len = max(len1, len2);

        if(len1 != len2){
            ListNode* head = len1 < len2 ? l1 : l2;
            for(int i = 0; i < len - min(len1, len2); i ++){
                ListNode* node = new ListNode(0);
                node->next = head;
                head = node;
            }
            if(len1 < len2) l1 = head;
            else l2 = head;
        }

        int carry = 0;
        ListNode* res = go(l1, l2, carry);
        if(carry){
            ListNode* node = new ListNode(1);
            node->next = res;
            res = node;
        }
        return res;
    }

private:
    int get_length(ListNode* head){

        if(!head) return 0;
        return 1 + get_length(head->next);
    }

    ListNode* go(ListNode* l1, ListNode* l2, int& carry){

        if(!l1){
            assert(!l2);
            carry = 0;
            return NULL;
        }

        int c = 0;
        ListNode* next = go(l1->next, l2->next, c);
        int x = l1->val + l2->val + c;
        ListNode* res = new ListNode(x % 10);
        res->next = next;
        carry = x / 10;
        return res;
    }
};


int main() {

    return 0;
}