/// Source : https://leetcode.com/problems/insertion-sort-list/
/// Author : liuyubobobo
/// Time   : 2019-02-13

#include <iostream>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(n^2)
/// Space Compelxity: O(1)

/// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* createLinkedList(int arr[], int n){

    if(n == 0)
        return NULL;

    ListNode* head = new ListNode(arr[0]);
    ListNode* curNode = head;
    for(int i = 1 ; i < n ; i ++){
        curNode->next = new ListNode(arr[i]);
        curNode = curNode->next;
    }

    return head;
}

void printLinkedList(ListNode* head){

    ListNode* curNode = head;
    while(curNode != NULL){
        cout << curNode->val << " -> ";
        curNode = curNode->next;
    }

    cout << "NULL" << endl;

    return;
}

void deleteLinkedList(ListNode* head){

    ListNode* curNode = head;
    while(curNode != NULL){
        ListNode* delNode = curNode;
        curNode = curNode->next;
        delete delNode;
    }

    return;
}

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {

        if(!head || !head->next) return head;

        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;

        ListNode* pre = dummyHead->next;
        while(pre->next){
            int val = pre->next->val;
            ListNode* next = pre->next->next;
            ListNode* pi = dummyHead;
            for(; pi != pre; pi = pi->next)
                if(pi->next->val > val){
                    ListNode* pj = pi->next;
                    ListNode* swapNode = pre->next;

                    pi->next = swapNode;
                    swapNode->next = pj;
                    pre->next = next;

                    break;
                }

            if(pi == pre) pre = pre->next;
//            printLinkedList(dummyHead);
        }
        return dummyHead->next;
    }
};


int main() {

    int arr1[4] = {4, 2, 1, 3};
    ListNode* head1 = createLinkedList(arr1, 4);
    ListNode* res1 = Solution().insertionSortList(head1);
    printLinkedList(res1);
    deleteLinkedList(res1);

    int arr2[5] = {-1, 5, 3, 4, 0};
    ListNode* head2 = createLinkedList(arr2, 5);
    ListNode* res2 = Solution().insertionSortList(head2);
    printLinkedList(res2);
    deleteLinkedList(res2);

    return 0;
}