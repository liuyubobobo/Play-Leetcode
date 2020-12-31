/// Source : https://leetcode.com/problems/copy-list-with-random-pointer/description/
/// Author : liuyubobobo
/// Time   : 2018-09-14

#include <iostream>

using namespace std;


/// Link all the new nodes after every old node
/// Very fancy solution:)
///
/// Time Complexity: O(n)
/// Space Complexity: O(1)

/// Definition for singly-linked list with a random pointer.
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {

        if(!head)
            return NULL;

        RandomListNode* cur = head;
        while(cur){
            RandomListNode* next = cur->next;
            cur->next = new RandomListNode(cur->label);
            cur->next->next = next;
            cur = next;
        }

        cur = head;
        while(cur){
            if(cur->random)
                cur->next->random = cur->random->next;
            cur = cur->next->next;
        }

        cur = head;
        RandomListNode* ret = cur->next;
        while(cur->next->next){
            RandomListNode* next = cur->next->next;
            cur->next->next = next->next;
            cur->next = next;
            cur = next;
        }
        cur->next = NULL;

        return ret;
    }
};


int main() {

    return 0;
}