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


/// DFS with return value
/// Time Complexity: O(n)
/// Space Complexity: O(h)
class Solution {

public:
    Node* treeToDoublyList(Node* root) {

        if(!root) return root;

        pair<Node*, Node*> p = inOrder(root);
        p.second->right = p.first;
        p.first->left = p.second;
        return p.first;
    }

private:
    pair<Node*, Node*> inOrder(Node* node){

        Node* first, *tail;
        if(node->left){
            pair<Node*, Node*> left = inOrder(node->left);
            first = left.first;
            left.second->right = node;
            node->left = left.second;
        }
        else
            first = node;

        if(node->right){
            pair<Node*, Node*> right = inOrder(node->right);
            right.first->left = node;
            node->right = right.first;
            tail = right.second;
        }
        else
            tail = node;

        return make_pair(first, tail);
    }

    Node* getFirst(Node* node){

        Node* cur = node;
        if(cur->left) cur = cur->left;
        return cur;
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