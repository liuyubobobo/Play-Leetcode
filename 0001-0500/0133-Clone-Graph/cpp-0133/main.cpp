/// Source : https://leetcode.com/problems/clone-graph/description/
/// Author : liuyubobobo
/// Time   : 2018-08-30
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

/// Using Two Stacks and HashMap from label to Node
/// Time Complexity: O(V+E)
/// Space Complexity: O(V)
class Solution {
public:
    Node *cloneGraph(Node *node) {

        if(node == NULL)
            return NULL;

        Node* ret = new Node(node->val);

        stack<Node*> stack1;
        stack1.push(node);
        unordered_map<int, Node*> visited;
        visited[ret->val] = ret;

        stack<Node*> stack2;
        stack2.push(ret);

        while(!stack1.empty()){
            Node* old_cur = stack1.top();
            stack1.pop();

            Node* new_cur = stack2.top();
            stack2.pop();

            for(Node *next: old_cur->neighbors) {
                if (visited.find(next->val) == visited.end()) {
                    visited[next->val] = new Node(next->val);
                    stack1.push(next);
                    stack2.push(visited[next->val]);
                }
                new_cur->neighbors.push_back(visited[next->val]);
            }
        }
        return ret;
    }
};


int main() {

    return 0;
}