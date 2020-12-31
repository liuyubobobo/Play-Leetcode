/// Source : https://leetcode.com/problems/maximum-depth-of-n-ary-tree/description/
/// Author : liuyubobobo
/// Time   : 2018-10-03

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


/// Using Stack - Non recursion
///
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

        stack<pair<Node*, int>> stack;
        stack.push(make_pair(root, 1));
        int res = 1;
        while(!stack.empty()){
            Node* cur = stack.top().first;
            int depth = stack.top().second;
            stack.pop();

            res = max(res, depth);

            for(Node* node: cur->children)
                stack.push(make_pair(node, depth + 1));
        }
        return res;
    }
};


int main() {

    return 0;
}