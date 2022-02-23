/// Source : https://leetcode.com/problems/clone-graph/description/
/// Author : liuyubobobo
/// Time   : 2018-09-14
/// Updated: 2022-02-22

#include <iostream>
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

/// DFS
/// Time Complexity: O(V+E)
/// Space Complexity: O(V)
class Solution {

public:
    Node *cloneGraph(Node *node) {

        if(node == NULL)
            return NULL;

        unordered_map<Node*, Node*> nodeMap;
        return dfs(node, nodeMap);
    }

private:
    Node *dfs(Node *node, unordered_map<Node*, Node*>& nodeMap){

        if(nodeMap.count(node))
            return nodeMap[node];

        nodeMap[node] = new Node(node->val);
        for(Node* next: node->neighbors)
            nodeMap[node]->neighbors.push_back(dfs(next, nodeMap));
        return nodeMap[node];
    }
};


int main() {

    return 0;
}