/// Source : https://leetcode.com/problems/copy-list-with-random-pointer/description/
/// Author : liuyubobobo
/// Time   : 2018-09-14

#include <iostream>
#include <unordered_map>

using namespace std;


/// Using HashMap
/// Treat the RandomList as a Graph and using DFS
///
/// Time Complexity: O(n)
/// Space Complexity: O(n)

/// Definition for singly-linked list with a random pointer.
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {

        if(!head) return NULL;

        // oldNode -> newNode
        unordered_map<RandomListNode*, RandomListNode*> nodeMap;
        return dfs(head, nodeMap);
    }

private:
    RandomListNode* dfs(RandomListNode* oldNode,
                        unordered_map<RandomListNode*, RandomListNode*>& nodeMap){

        if(nodeMap.count(oldNode))
            return nodeMap[oldNode];

        nodeMap[oldNode] = new RandomListNode(oldNode->label);
        if(oldNode->next)
            nodeMap[oldNode]->next = dfs(oldNode->next, nodeMap);

        if(oldNode->random)
            nodeMap[oldNode]->random = dfs(oldNode->random, nodeMap);

        return nodeMap[oldNode];
    }
};


int main() {

    return 0;
}