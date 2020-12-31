/// Source : https://leetcode.com/problems/maximum-depth-of-n-ary-tree/description/
/// Author : liuyubobobo
/// Time   : 2018-10-03

#include <iostream>
#include <vector>

using namespace std;


/// DFS
/// Time Complexity: O(n)
/// Space Complexity: O(n)

/// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    int maxDepth(Node* root) {

        if(!root)
            return 0;

        int res = 1;
        for(Node* child: root->children)
            res = max(res, 1 + maxDepth(child));
        return res;
    }
};


int main() {

    return 0;
}