/// Source : https://leetcode.com/problems/split-linked-list-in-parts/description/
/// Author : liuyubobobo
/// Time   : 2017-11-12

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


/// Create New Lists
/// Time Complexity: O(len(list))
/// Space Complexity: O(1)
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {

        int length = getLength(root);

        int average_size = length / k;
        int left = length % k;

        vector<ListNode*> res;
        for(int i = 0 ; i < k ; i ++){

            int sz = average_size + (i < left ? 1 : 0);

            if(sz == 0)
                res.push_back(NULL);
            else{
                ListNode* dummyRoot = new ListNode(-1);
                ListNode* cur = dummyRoot;
                for(int i = 0 ; i < sz ; i ++){
                    cur->next = new ListNode(root->val);
                    cur = cur->next;
                    root = root->next;
                }
                res.push_back(dummyRoot->next);
                dummyRoot->next = NULL;
                delete dummyRoot;
            }
        }

        return res;
    }

private:
    int getLength(ListNode* node){

        int cnt = 0;
        while(node != NULL){
            cnt ++;
            node = node->next;
        }
        return cnt;
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

void printLinkedList(ListNode* head){

    ListNode* curNode = head;
    while( curNode != NULL ){
        cout << curNode->val << " -> ";
        curNode = curNode->next;
    }

    cout<<"NULL"<<endl;

    return;
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

    int nums1[3] = {1, 2, 3};
    ListNode* root1 = createLinkedList(nums1, 3);
    int k1 = 5;

    vector<ListNode*> res1 = Solution().splitListToParts(root1, k1);
    for(ListNode* node: res1)
        printLinkedList(node);

    cout << endl;

    // ---

    int nums2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ListNode* root2 = createLinkedList(nums2, 10);
    int k2 = 3;

    vector<ListNode*> res2 = Solution().splitListToParts(root2, k2);
    for(ListNode* node: res2)
        printLinkedList(node);

    cout << endl;

    return 0;
}