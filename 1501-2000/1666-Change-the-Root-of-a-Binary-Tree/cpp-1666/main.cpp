/// Source : https://leetcode.com/problems/change-the-root-of-a-binary-tree/
/// Author : liuyubobobo
/// Time   : 2020-11-30

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Recursion
/// Time Complexity: O(n)
/// Space Complexity: O(h)
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent = 0;

    Node(int v, Node* l, Node* r): val(v), left(l), right(r){}
    Node(int v): Node(v, 0, 0){}
};

class Solution {

public:
    Node* flipBinaryTree(Node* root, Node * leaf) {
        Node* res = flip(leaf);
        res->parent = nullptr;
        return res;
    }

private:
    Node* flip(Node* node){

        if(!node->parent) return node;

        if(node->parent->left == node)
            node->parent->left = nullptr;
        else
            node->parent->right = nullptr;

        if(node->left){
            node->right = node->left;
            node->right->parent = node;
        }
        node->left = flip(node->parent);
        node->left->parent = node;
        return node;
    }
};


int main() {

//    Node* leaf = new Node(7);
//    Node* four = new Node(4);
//    Node* two = new Node(2, leaf, four);
//
//    Node* six = new Node(6);
//    Node* five = new Node(5, six, two);
//
//    Node* zero = new Node(0);
//    Node* eight = new Node(8);
//    Node* one = new Node(1, zero, eight);
//
//    Node* root = new Node(3, five, one);
//
//    leaf->parent = two; four->parent = two;
//    two->parent = five; six->parent = five;
//    zero->parent = one; eight->parent = one;
//    five->parent = root; one->parent = root;
//
//    Node* res = Solution().flipBinaryTree(root, leaf);

    Node* seven = new Node(7);
    Node* four = new Node(4);
    Node* two = new Node(2, seven, four);

    Node* six = new Node(6);
    Node* five = new Node(5, six, two);

    Node* zero = new Node(0);
    Node* eight = new Node(8);
    Node* one = new Node(1, zero, eight);

    Node* three = new Node(3, five, one);

    seven->parent = two, four->parent = two;
    six->parent = five, two->parent = five;
    zero->parent = one, eight->parent = one;
    five->parent = three, one->parent = three;

    Node* res = Solution().flipBinaryTree(three, zero);

    return 0;
}
