/// Source : https://leetcode.com/problems/clone-graph/description/
/// Author : liuyubobobo
/// Time   : 2018-09-14

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/// Definition for undirected graph.
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

/// DFS
/// Time Complexity: O(V+E)
/// Space Complexity: O(V)
class Solution {

public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {

        if(node == NULL)
            return NULL;

        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> nodeMap;
        return dfs(node, nodeMap);
    }

private:
    UndirectedGraphNode *dfs(UndirectedGraphNode *node,
                             unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>& nodeMap){

        if(nodeMap.count(node))
            return nodeMap[node];

        nodeMap[node] = new UndirectedGraphNode(node->label);
        for(UndirectedGraphNode* next: node->neighbors)
            nodeMap[node]->neighbors.push_back(dfs(next, nodeMap));
        return nodeMap[node];
    }
};


int main() {

    return 0;
}