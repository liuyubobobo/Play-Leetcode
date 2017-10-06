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
 * Reverse a singly linked list.
 ***************************************************************************************/


/// Solution
/**************************************************************************************
 * Non-recursion implementation
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 **************************************************************************************/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        if( head == NULL )
            return NULL;

        ListNode* pre = NULL;
        ListNode* cur = head;
        ListNode* nxt = cur->next;
        while( true ){
            cur->next = pre;
            pre = cur;
            cur = nxt;
            if( cur == NULL )
                break;
            else
                nxt = cur->next;
        }

        return pre;
    }
};

int main(){

    int n = 5;
    int arr[] = {1, 2, 3, 4, 5};

    ListNode* head = createLinkedList(arr, n);
    printLinkedList(Solution().reverseList(head));

    return 0;
}