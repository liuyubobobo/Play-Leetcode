#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
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

void printLinkedList(ListNode* head){

    if( head == NULL ){
        cout<<"NULL"<<endl;
        return;
    }

    ListNode* curNode = head;
    while( curNode != NULL ){
        cout<<curNode->val;
        if( curNode->next != NULL )
            cout<<" -> ";
        curNode = curNode->next;
    }

    cout<<endl;

    return;
}


/// Problem
/***************************************************************************************
 *
 * Merge two sorted linked lists and return it as a new list.
 * The new list should be made by splicing together the nodes of the first two lists.
 ***************************************************************************************/


/// Solution
/**************************************************************************************
 * Basic merge process implementation.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 **************************************************************************************/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        ListNode* dummyHead = new ListNode(0);
        ListNode* p = dummyHead;
        while( l1 != NULL && l2 != NULL ){
            if( l1->val <= l2->val ){
                p->next = l1;
                l1 = l1->next;
            }
            else{ // l1->val > l2->val
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }

        if( l1 != NULL )
            p->next = l1;
        if( l2 != NULL )
            p->next = l2;

        ListNode *ret = dummyHead->next;
        delete dummyHead;
        return ret;
    }
};

int main(){

    int n = 5;
    int arr1[] = {1, 3, 5, 7, 9};
    int arr2[] = {0, 2, 4, 6, 8};

    ListNode* head1 = createLinkedList(arr1, n);
    printLinkedList(head1);

    ListNode* head2 = createLinkedList(arr2, n);
    printLinkedList(head2);

    ListNode* res = Solution().mergeTwoLists(head1, head2);
    printLinkedList(res);

    return 0;
}