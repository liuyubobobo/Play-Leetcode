/// Source : https://leetcode.com/problems/maximum-depth-of-n-ary-tree/description/
/// Author : liuyubobobo
/// Time   : 2018-10-03

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// BFS
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

        queue<pair<Node*, int>> q;
        q.push(make_pair(root, 1));
        int res = 1;
        while(!q.empty()){
            Node* cur = q.front().first;
            int depth = q.front().second;
            q.pop();

            res = max(res, depth);

            for(Node* node: cur->children)
                q.push(make_pair(node, depth + 1));
        }
        return res;
    }
};


int main() {

    return 0;
}