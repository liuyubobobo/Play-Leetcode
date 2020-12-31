/// Source : https://leetcode.com/problems/insert-into-a-cyclic-sorted-list/description/
/// Author : liuyubobobo
/// Time   : 2018-10-02

#include <iostream>

using namespace std;


/// Linear Scan
/// Time Complexity: O(n)
/// Space Complexity: O(1)

/// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};

class Solution {
public:
    Node* insert(Node* head, int insertVal) {

        if(head == NULL){
            Node* ret = new Node(insertVal, NULL);
            ret->next = ret;
            return ret;
        }

        Node* pre = head;
        while(pre->next != head){
            if((insertVal >= pre->val && insertVal <= pre->next->val) ||
                    (pre->next->val < pre->val &&
                            (insertVal < pre->next->val || insertVal >= pre->val)))
                break;

            pre = pre->next;
        }
        pre->next = new Node(insertVal, pre->next);
        return head;
    }
};


int main() {

    Node* head = new Node(1, NULL);

    Node* node2 = new Node(2, NULL);
    head->next = node2;

    Node* node3 = new Node(3, NULL);
    node2->next = node3;
    node3->next = head;

    Solution().insert(head, 0);

    return 0;
}