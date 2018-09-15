/// Source : https://leetcode.com/problems/clone-graph/description/
/// Author : liuyubobobo
/// Time   : 2018-08-30

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

/// Using Two Stacks and HashMap from label to Node
/// Time Complexity: O(V+E)
/// Space Complexity: O(V)
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {

        if(node == NULL)
            return NULL;

        UndirectedGraphNode* ret = new UndirectedGraphNode(node->label);

        stack<UndirectedGraphNode*> stack1;
        stack1.push(node);
        unordered_map<int, UndirectedGraphNode*> visited;
        visited[ret->label] = ret;

        stack<UndirectedGraphNode*> stack2;
        stack2.push(ret);

        while(!stack1.empty()){
            UndirectedGraphNode* old_cur = stack1.top();
            stack1.pop();

            UndirectedGraphNode* new_cur = stack2.top();
            stack2.pop();

            for(UndirectedGraphNode *next: old_cur->neighbors) {
                if (visited.find(next->label) == visited.end()) {
                    visited[next->label] = new UndirectedGraphNode(next->label);
                    stack1.push(next);
                    stack2.push(visited[next->label]);
                }
                new_cur->neighbors.push_back(visited[next->label]);
            }
        }
        return ret;
    }
};


int main() {

    return 0;
}