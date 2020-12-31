/// Source : https://leetcode.com/problems/add-two-numbers-ii/
/// Author : liuyubobobo
/// Time   : 2019-09-21

#include <iostream>
#include <stack>

using namespace std;


/// Using Stack
/// Time Complexity: O(m + n + max(m, n))
/// Space Complexity: O(m + n)

/// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        stack<ListNode*> stack1, stack2, stack;
        ListNode* node = l1;
        while(node) stack1.push(node), node = node->next;
        node = l2;
        while(node) stack2.push(node), node = node->next;

        int carry = 0;
        while(!stack1.empty() || !stack2.empty() || carry){

            int x = 0;
            if(!stack1.empty()) x += stack1.top()->val, stack1.pop();
            if(!stack2.empty()) x += stack2.top()->val, stack2.pop();
            x += carry;

            stack.push(new ListNode(x % 10));
            carry = x / 10;
        }

        ListNode* ret = stack.top(), *cur = ret;
        stack.pop();
        while(!stack.empty())
            cur->next = stack.top(), cur = cur->next, stack.pop();
        return ret;
    }
};


int main() {

    return 0;
}