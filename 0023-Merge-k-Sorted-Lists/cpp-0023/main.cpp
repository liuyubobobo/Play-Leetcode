/// Source : https://leetcode.com/problems/merge-k-sorted-lists/description/
/// Author : liuyubobobo
/// Time   : 2018-07-02

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/// Linear Compare each ListNode
/// Time Complexity: O(k*n) where k is len(lists) and n is the nodes number
/// Space Complexity: O(1)
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if(lists.size() == 0)
            return NULL;

        ListNode* dummyHead = new ListNode(-1);
        ListNode* curNode = dummyHead;

        int finished = 0;
        for(ListNode* node: lists)
            if(node == NULL)
                finished ++;

        while(finished < lists.size()){

            ListNode* nextNode = NULL;
            int nextIndex = -1;
            for(int i = 0 ; i < lists.size() ; i ++)
                if(lists[i] != NULL){
                    if(nextIndex == -1 || lists[i]->val < nextNode->val){
                        nextNode = lists[i];
                        nextIndex = i;
                    }
                }
            assert(nextIndex != -1 && nextNode != NULL);

            lists[nextIndex] = lists[nextIndex]->next;
            if(lists[nextIndex] == NULL)
                finished ++;

            curNode->next = nextNode;
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