/// Source : https://leetcode.com/problems/inorder-successor-in-bst-ii/s
/// Author : liuyubobobo
/// Time   : 2022-07-08

#include <iostream>
#include <vector>

using namespace std;


/// Tree Algorithm
/// Time Compelxity: O(h)
/// Space Compelxity: O(1)

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};

class Solution {
public:
    Node* inorderSuccessor(Node* node) {

        if(node->right){
            return minimum(node->right);
        }

        Node* cur = node, *pre = node->parent;
        while(pre){
            if(pre->left == cur){
                return pre;
            }
            else{
                cur = pre;
                pre = cur->parent;
            }
        }
        return nullptr;
    }

private:
    Node* minimum(Node* node){
        while(node->left) node = node->left;
        return node;
    }
};


int main() {

    return 0;
}
