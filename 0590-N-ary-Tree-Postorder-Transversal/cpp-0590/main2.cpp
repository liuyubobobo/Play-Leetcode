/// Source : https://leetcode.com/problems/n-ary-tree-postorder-traversal/
/// Author : liuyubobobo
/// Time   : 2018-10-29

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


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

/// Non-Recursion
/// Using stack
///
/// Time Complexity: O(n)
/// Space Complexity: O(h)
class Solution {
public:
    vector<int> postorder(Node* root) {

        vector<int> res;
        if(!root)
            return res;

        stack<Node*> stack;
        stack.push(root);
        while(!stack.empty()){
            Node* cur = stack.top();
            stack.pop();
            res.push_back(cur->val);
            for(Node* next: cur->children)
                stack.push(next);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};


int main() {

    return 0;
}