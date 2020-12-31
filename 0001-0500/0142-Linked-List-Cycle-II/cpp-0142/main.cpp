/// Source : https://leetcode.com/problems/linked-list-cycle-ii/description/
/// Author : liuyubobobo
/// Time   : 2017-12-09

#include <iostream>
#include <cassert>
#include <set>

using namespace std;


/// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/// Using Hash
///
/// Time Complexity: O(N)
/// Space Complexity: O(N)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        if(head == NULL || head->next == NULL)
            return NULL;

        set<ListNode*> records;
        ListNode* curNode = head;
        while(curNode != NULL){
            if(records.find(curNode) != records.end())
                return curNode;

            records.insert(curNode);
            curNode = curNode->next;
        }

        return NULL;
    }
};

/// LinkedList Test Helper Functions
ListNode* createLinkedList(int arr[], int n){

    if( n == 0 )
        return NULL;

    ListNode* head = new ListNode(arr[0]);
    ListNode* curNode = head;
    for( int i = 1 ; i < n ; i ++ ){
        curNode->next = new ListNode(arr[i]);
        curNode = curNode->next;
    }

    return head;
}

ListNode* tail(ListNode* head){

    if(head == NULL)
        return NULL;

    ListNode* curNode = head;
    while(curNode->next != NULL)
        curNode = curNode->next;

    return curNode;
}

void deleteLinkedList(ListNode* head){

    ListNode* curNode = head;
    while( curNode != NULL ){
        ListNode* delNode = curNode;
        curNode = curNode->next;
        delete delNode;
    }

    return;
}

int main() {

    int n1 = 2;
    int nums1[2] = {1, 2};
    ListNode* head1 = createLinkedList(nums1, n1);

    ListNode* entrance1 = Solution().detectCycle(head1);
    if(entrance1 != NULL)
        cout << "Loop entrance at " << entrance1->val << endl;
    else
        cout << "No Loop" << endl;

    deleteLinkedList(head1);

    // ---

    int n2 = 2;
    int nums2[2] = {1, 2};
    ListNode* head2 = createLinkedList(nums2, n2);
    ListNode* tail2 = tail(head2);
    tail2->next = head2;

    ListNode* entrance2 = Solution().detectCycle(head2);
    if(entrance2)
        cout << "Loop entrance at " << entrance2->val << endl;
    else
        cout << "No Loop" << endl;

    tail2->next = NULL;
    deleteLinkedList(head2);

    return 0;
}