/// Source : https://leetcode.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/
/// Author : liuyubobobo
/// Time   : 2019-04-09

#include <iostream>

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};


/// DFS with reference value
/// Time Complexity: O(n)
/// Space Complexity: O(h)
class Solution {

public:
    Node* treeToDoublyList(Node* root) {

        if(!root) return root;

        Node* first, *tail;
        inOrder(root, first, tail);
        tail->right = first;
        first->left = tail;
        return first;
    }

private:
    void inOrder(Node* node, Node*& first, Node*& tail){

        if(node->left){
            inOrder(node->left, first, tail);
            tail->right = node;
            node->left = tail;
        }
        else
            first = node;

        if(node->right){
            Node* rFirst;
            inOrder(node->right, rFirst, tail);
            rFirst->left = node;
            node->right = rFirst;
        }
        else
            tail = node;

        return;
    }
};


void print_list(Node* head){

    if(head){
        cout << head->val << " -> ";
        Node* cur = head->right;
        while(cur != head){
            cout << cur->val << " -> ";
            cur = cur->right;
        }
    }
    cout << "NULL" << endl;
}

int main() {

    Node* one = new Node(1, NULL, NULL);
    Node* three = new Node(3, NULL, NULL);
    Node* two = new Node(2, one, three);
    Node* five = new Node(5, NULL, NULL);
    Node* four = new Node(4, two, five);

    print_list(Solution().treeToDoublyList(four));

    return 0;
}