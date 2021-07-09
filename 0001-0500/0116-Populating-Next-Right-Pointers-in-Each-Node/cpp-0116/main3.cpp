/// Source : https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/
/// Author : liuyubobobo
/// Time   : 2018-10-19
/// Updated: 2021-07-09

#include <iostream>
#include <queue>
#include <cassert>

using namespace std;


/// BFS without queue
/// Since the upper level have already been a linked list
/// We can traverse the upper level in a linked list way to connect the lower level
/// Actually, the upper linked list is our queue :-)
///
/// Time Complexity: O(n)
/// Space Compelxity: O(1)

/// Definition for binary tree with next pointer.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {

public:
    Node* connect(Node *root) {

        if(!root) return nullptr;

        Node* node = root;
        while(node->left){
            Node* p = node;
            Node* dummyHead = new Node(-1);
            Node* cur = dummyHead;
            while(p){
                cur->next = p->left;
                cur = cur->next;

                cur->next = p->right;
                cur = cur->next;

                p = p->next;
            }

            delete dummyHead;
            node = node->left;
        }
        return root;
    }
};


int main() {

    return 0;
}