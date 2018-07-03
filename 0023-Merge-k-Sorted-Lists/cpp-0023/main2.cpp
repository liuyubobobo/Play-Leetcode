/// Source : https://leetcode.com/problems/merge-k-sorted-lists/description/
/// Author : liuyubobobo
/// Time   : 2018-07-02

#include <iostream>
#include <vector>
#include <cassert>
#include <queue>

using namespace std;

/// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class CompareListNode{
public:
    bool operator()(ListNode* node1, ListNode* node2){
        return node1->val > node2->val;
    }
};

/// Using Priority Queue to compare each ListNode
/// Time Complexity: O(nlogk) where k is len(lists) and n is the nodes number
/// Space Complexity: O(1)
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if(lists.size() == 0)
            return NULL;

        ListNode* dummyHead = new ListNode(-1);
        ListNode* curNode = dummyHead;

        priority_queue<ListNode*, vector<ListNode*>, CompareListNode> q;
        for(ListNode* node: lists)
            if(node != NULL)
                q.push(node);

        while(!q.empty()){

            ListNode* nextNode = q.top();
            q.pop();


            curNode->next = nextNode;
            if(nextNode->next != NULL)
                q.push(nextNode->next);

            nextNode->next = NULL;
            curNode = curNode->next;
        }

        ListNode* ret = dummyHead->next;
        delete dummyHead;
        return ret;
    }
};


int main() {

    return 0;
}