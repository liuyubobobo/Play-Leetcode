/// Source : https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/description/
/// Author : liuyubobobo
/// Time   : 2018-10-02

#include <iostream>

using namespace std;


/// DFS
/// Time Complexity: O(n)
/// Space Complexity: O(n)

/// Definition for a Node.
class Node {

public:
    int val = NULL;
    Node* prev = NULL;
    Node* next = NULL;
    Node* child = NULL;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};


class Solution {
public:
    Node* flatten(Node* head) {

        if(!head)
            return NULL;

        Node* tail;
        return flatten(head, tail);
    }

private:
    Node* flatten(Node* head, Node*& tail){

        Node* cur = head;
        while(cur){
            if(cur->child){
                Node* subtail;
                Node* subhead = flatten(cur->child, subtail);
                Node* next = cur->next;

                cur->next = subhead;
                subhead->prev = cur;
                subtail->next = next;

                if(next)
                    next->prev = subtail;
                else
                    tail = subtail;

                cur->child = NULL;
                cur = next;
            }
            else{
                if(!cur->next)
                    tail = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};


int main() {

    return 0;
}