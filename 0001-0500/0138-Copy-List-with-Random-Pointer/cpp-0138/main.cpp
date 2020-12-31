/// Source : https://leetcode.com/problems/copy-list-with-random-pointer/description/
/// Author : liuyubobobo
/// Time   : 2018-09-14

#include <iostream>
#include <unordered_map>

using namespace std;


/// Using HashMap
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

        // oldNode -> newNode
        unordered_map<RandomListNode*, RandomListNode*> nodeMap;

        RandomListNode* dummyHead = new RandomListNode(-1);
        RandomListNode* pre = dummyHead;
        RandomListNode* node = head;
        while(node){
            if(!nodeMap.count(node))
                nodeMap[node] = new RandomListNode(node->label);
            pre->next = nodeMap[node];
            pre = pre->next;

            if(node->random){
                if(!nodeMap.count(node->random))
                    nodeMap[node->random] = new RandomListNode(node->random->label);
                pre->random = nodeMap[node->random];
            }

            node = node->next;
        }

        RandomListNode* ret = dummyHead->next;
        delete dummyHead;
        return ret;
    }
};


int main() {

    return 0;
}