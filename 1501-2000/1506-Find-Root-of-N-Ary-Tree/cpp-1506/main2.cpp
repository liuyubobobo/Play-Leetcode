/// Source : https://leetcode.com/problems/find-root-of-n-ary-tree/
/// Author : liuyubobobo
/// Time   : 2021-01-08

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/// Using xor
/// Time Complexity: O(n)
/// Space Complexity: O(1)

// Definition for a Node.
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
    Node* findRoot(vector<Node*> tree) {

        int x = 0;
        for(Node* node: tree){
            x ^= node->val;
            for(Node* next: node->children)
                x ^= next->val;
        }

        for(Node* node: tree)
            if(node->val == x) return node;
        return nullptr;
    }
};


int main() {

    return 0;
}
