/// Source : https://leetcode.com/problems/design-linked-list/description/
/// Author : liuyubobobo
/// Time   : 2018-10-01

#include <iostream>

using namespace std;


/// Doubly Linked List
/// Without dummyhead;
/// Time Complexity: init: O(1)
///                  get: O(n)
///                  addAtHead: O(1)
///                  addAtTail: O(n)
///                  addAtIndex: O(n)
///                  deleteAtIndex: O(n)
/// Space Complexity: O(n)
class MyLinkedList {

private:
    class Node{
    public:
        int val;
        Node* next;
        Node* prev;

        Node(int val, Node* prev, Node* next): val(val), prev(prev), next(next){}
        Node(int val): Node(val, NULL, NULL){}
    };

    Node* head;

public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = NULL;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {

        Node* cur = head;
        for(int i = 0; i < index && cur; i ++)
            cur = cur->next;

        if(!cur) return -1;
        return cur->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        head = new Node(val, NULL, head);
        if(head->next)
            head->next->prev = head;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {

        if(head == NULL)
            head = new Node(val);
        else{
            Node* pre = head;
            while(pre->next)
                pre = pre->next;
            pre->next = new Node(val, pre, NULL);
        }
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {

        if(index == 0)
            addAtHead(val);
        else{
            Node* pre = head;
            for(int i = 1; i < index && pre; i ++)
                pre = pre->next;

            if(pre)
                pre->next = new Node(val, pre, pre->next);
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index == 0){
            if(head){
                Node* delNode = head;
                head = head->next;
                if(head)
                    head->prev = NULL;
                delete delNode;
            }
        }
        else{
            Node* pre = head;
            for(int i = 1; i < index && pre; i ++)
                pre = pre->next;

            if(pre && pre->next){
                Node* delNode = pre->next;
                pre->next = delNode->next;
                if(pre->next)
                    pre->next->prev = pre;
                delete delNode;
            }
        }
    }
};


int main() {

    return 0;
}