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


/// BFS
/// Store step in the queue
///
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {

        vector<vector<int>> res;
        if(!root)
            return res;

        queue<pair<Node*, int>> q;
        q.push(make_pair(root, 0));
        while(!q.empty()){
            Node* cur = q.front().first;
            int step = q.front().second;
            q.pop();

            if(step == res.size())
                res.push_back({cur->val});
            else
                res[step].push_back(cur->val);

            for(Node* next: cur->children)
                q.push(make_pair(next, step + 1));
        }

        return res;
    }
};


int main() {

    return 0;
}