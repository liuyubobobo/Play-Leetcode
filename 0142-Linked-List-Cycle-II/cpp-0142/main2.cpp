/// Source : https://leetcode.com/problems/linked-list-cycle-ii/description/
/// Author : liuyubobobo
/// Time   : 2017-11-03

#include <iostream>
#include <cassert>

using namespace std;


/// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/// Two Pointers - Floyd's Tortoise and Hare
///
/// A great overview for the algorithm is here:
/// -- https://stackoverflow.com/questions/3952805/proof-of-detecting-the-start-of-cycle-in-linked-list
///
/// UPDATE: 09 Dec 2017
/// The official solution in leetcode is extremely great for this problem:
/// https://leetcode.com/problems/linked-list-cycle-ii/solution/#approach-2-floyds-tortoise-and-hare-accepted
///
/// Time Complexity: O(N)
/// Space Complexity: O(1)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        if(head == NULL || head->next == NULL)
            return NULL;

        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;

        ListNode* slow = dummyHead;
        ListNode* fast = dummyHead;
        do{

            if(fast->next == NULL || fast->next->next == NULL)
                return NULL;

            fast = fast->next->next;
            slow = slow->next;
        }while(slow != fast);

        // cout << "Meet Point: " << slow->val << endl;

        ListNode* entrance = slow;
        assert(entrance == fast);

        ListNode* p = dummyHead;
        while(p != entrance){
            p = p->next;
            entrance = entrance->next;
        }

        delete dummyHead;

        return entrance;
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