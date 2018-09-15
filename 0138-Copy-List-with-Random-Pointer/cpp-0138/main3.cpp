/// Source : https://leetcode.com/problems/copy-list-with-random-pointer/description/
/// Author : liuyubobobo
/// Time   : 2018-09-14

#include <iostream>
#include <unordered_map>
#include <stack>

using namespace std;


/// Using HashMap
/// Treat the RandomList as a Graph and using Stack
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

        RandomListNode* ret = new RandomListNode(head->label);
        stack<RandomListNode*> stack;
        stack.push(head);
        nodeMap[head] = ret;
        while(!stack.empty()){
            RandomListNode* cur = stack.top();
            stack.pop();

            if(cur->next) {
                if (!nodeMap.count(cur->next)) {
                    nodeMap[cur->next] = new RandomListNode(cur->next->label);
                    stack.push(cur->next);
                }
                nodeMap[cur]->next = nodeMap[cur->next];
            }

            if(cur->random){
                if(!nodeMap.count(cur->random)){
                    nodeMap[cur->random] = new RandomListNode(cur->random->label);
                    stack.push(cur->random);
                }
                nodeMap[cur]->random = nodeMap[cur->random];
            }
        }

        return ret;
    }
};


int main() {

    return 0;
}