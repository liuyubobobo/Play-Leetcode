/// Source : https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/
/// Author : liuyubobobo
/// Time   : 2021-09-01

#include <iostream>

using namespace std;


/// Two Pointers
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
    ListNode* getKthFromEnd(ListNode* head, int k) {

        ListNode* b = head;
        for(int i = 0; i < k; i ++) b = b->next;

        ListNode* a = head;
        while(b) a = a->next, b = b->next;
        return a;
    }
};


int main() {

    return 0;
}
