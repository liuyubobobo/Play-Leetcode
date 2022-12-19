/// Source : https://leetcode.com/problems/remove-nodes-from-linked-list/description/
/// Author : liuyubobobo
/// Time   : 2022-12-18

#include <iostream>
#include <vector>

using namespace std;


/// Mono Stack
/// Time Complexity: O(n)
/// Space Compelxity: O(n)

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
    ListNode* removeNodes(ListNode* head) {

        vector<ListNode*> stack;
        for(ListNode* node = head; node; node = node->next){
            while(!stack.empty() && stack.back()->val < node->val) stack.pop_back();
            stack.push_back(node);
        }

        for(int i = 0; i + 1 < stack.size(); i ++)
            stack[i]->next = stack[i + 1];
        stack.back()->next = nullptr;
        return stack[0];
    }
};


int main() {

    return 0;
}
