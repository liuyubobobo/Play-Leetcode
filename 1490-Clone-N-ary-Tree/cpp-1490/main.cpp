/// Source : https://leetcode.com/problems/clone-n-ary-tree/
/// Author : liuyubobobo
/// Time   : 2020-06-24

#include <iostream>
#include <vector>

using namespace std;


/// DFS
/// Time Complexity: O(n)
/// Space Complexity: O(h)

/// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    Node* cloneTree(Node* root) {

        if(!root) return root;

        Node* ret = new Node(root->val);
        for(Node* node: root->children)
            ret->children.push_back(cloneTree(node));
        return ret;
    }
};


int main() {

    return 0;
}
