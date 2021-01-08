/// Source : https://leetcode.com/problems/find-root-of-n-ary-tree/
/// Author : liuyubobobo
/// Time   : 2021-01-08

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/// Using HashSet
/// Time Complexity: O(n)
/// Space Complexity: O(n)

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

        unordered_set<Node*> set;
        for(Node* node: tree)
            for(Node* next: node->children)
                set.insert(next);

        for(Node* node: tree)
            if(!set.count(node)) return node;
        return nullptr;
    }
};


int main() {

    return 0;
}
