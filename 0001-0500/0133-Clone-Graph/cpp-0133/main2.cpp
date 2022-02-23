/// Source : https://leetcode.com/problems/clone-graph/description/
/// Author : liuyubobobo
/// Time   : 2018-09-14
/// Updated: 2022-02-22

#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>

using namespace std;

/// Definition for undirected graph.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

/// Using Only One Stacks and HashMap from Node to Node
/// Time Complexity: O(V+E)
/// Space Complexity: O(V)
class Solution {
public:
    Node *cloneGraph(Node *node) {

        if(node == NULL)
            return NULL;

        Node* ret = new Node(node->val);
        stack<Node*> stack;
        stack.push(node);
        unordered_map<Node*, Node*> nodeMap;
        nodeMap[node] = ret;
        while(!stack.empty()){
            Node* cur = stack.top();
            stack.pop();
            for(Node *next: cur->neighbors) {
                if (!nodeMap.count(next)) {
                    nodeMap[next] = new Node(next->val);
                    stack.push(next);
                }
                nodeMap[cur]->neighbors.push_back(nodeMap[next]);
            }
        }
        return ret;
    }
};


int main() {

    return 0;
}