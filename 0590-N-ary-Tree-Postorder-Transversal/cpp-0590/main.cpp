/// Source : https://leetcode.com/problems/n-ary-tree-postorder-traversal/
/// Author : liuyubobobo
/// Time   : 2018-10-29

#include <iostream>
#include <vector>

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

/// Recursion
/// Time Complexity: O(n)
/// Space Complexity: O(h)
class Solution {
public:
    vector<int> postorder(Node* root) {

        vector<int> res;
        dfs(root, res);
        return res;
    }

private:
    void dfs(Node* node, vector<int>& res){

        if(!node)
            return;

        for(Node* next: node->children)
            dfs(next, res);
        res.push_back(node->val);
    }
};


int main() {

    return 0;
}