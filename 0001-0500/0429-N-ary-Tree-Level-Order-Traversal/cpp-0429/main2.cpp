/// Source : https://leetcode.com/problems/n-ary-tree-level-order-traversal/
/// Author : liuyubobobo
/// Time   : 2018-10-30

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


/// BFS, using Queue
/// No need to store step in the queue :-)
///
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {

        vector<vector<int>> res;
        if(!root)
            return res;

        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> level;
            for(int i = 0; i < n; i ++){
                Node* node = q.front();
                q.pop();
                level.push_back(node->val);
                for(Node* next: node->children)
                    q.push(next);
            }
            res.push_back(level);
        }

        return res;
    }
};


int main() {

    return 0;
}