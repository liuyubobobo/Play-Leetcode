/// Source : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iii/
/// Author : liuyubobobo
/// Time   : 2020-11-14

#include <iostream>
#include <unordered_set>

using namespace std;


/// Using HashMap
/// Time Complexity: O(h)
/// Space Complexity: O(h)

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
    Node* lowestCommonAncestor(Node* p, Node * q) {

        unordered_set<Node*> set;
        while(p) set.insert(p), p = p->parent;

        while(q){
            if(set.count(q)) return q;
            q = q->parent;
        }
        return nullptr;
    }
};


int main() {

    return 0;
}
