/// Source : https://leetcode.com/problems/n-ary-tree-preorder-traversal/
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
/// Time Complexity: O(n)
/// Space Complexity: O(h)
class Solution {
public:
    vector<int> preorder(Node* root) {

        vector<int> res;
        if(!root)
            return res;

        stack<pair<Node*, int>> stack;
        stack.push(make_pair(root, 1));
        while(!stack.empty()){
            Node* cur = stack.top().first;
            int step = stack.top().second;
            stack.pop();

            res.push_back(cur->val);
            for(vector<Node*>::reverse_iterator iter = cur->children.rbegin();
                    iter != cur->children.rend(); iter ++)
                stack.push(make_pair(*iter, step + 1));
        }
        return res;
    }
};


int main() {

    return 0;
}