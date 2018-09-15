/// Source : https://leetcode.com/problems/clone-graph/description/
/// Author : liuyubobobo
/// Time   : 2018-09-14

#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>

using namespace std;

/// Definition for undirected graph.
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

/// Using Only One Stacks and HashMap from Node to Node
/// Time Complexity: O(V+E)
/// Space Complexity: O(V)
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {

        if(node == NULL)
            return NULL;

        UndirectedGraphNode* ret = new UndirectedGraphNode(node->label);
        stack<UndirectedGraphNode*> stack;
        stack.push(node);
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> nodeMap;
        nodeMap[node] = ret;
        while(!stack.empty()){
            UndirectedGraphNode* cur = stack.top();
            stack.pop();
            for(UndirectedGraphNode *next: cur->neighbors) {
                if (!nodeMap.count(next)) {
                    nodeMap[next] = new UndirectedGraphNode(next->label);
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