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

/// Merge List One by One
/// Time Complexity: O(k*n), where k is len(lists) and n is the nodes number
/// Space Complexity: O(1)
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if(lists.size() == 0)
            return NULL;

        ListNode* ret = NULL;
        for(ListNode* list: lists)
            ret = merge(ret, list);
        return ret;
    }

private:
    ListNode* merge(ListNode* list1, ListNode* list2){

        ListNode* dummyHead = new ListNode(-1);
        ListNode* curNode = dummyHead;
        while(list1 != NULL && list2 != NULL){
            if(list1->val < list2->val){
                curNode->next = list1;
                list1 = list1->next;
            }
            else{
                curNode->next = list2;
                list2 = list2->next;
            }

            curNode = curNode->next;
            curNode->next = NULL;
        }

        if(list1)
            curNode->next = list1;
        if(list2)
            curNode->next = list2;

        ListNode* ret = dummyHead->next;
        delete dummyHead;
        return ret;
    }
};


int main() {

    return 0;
}