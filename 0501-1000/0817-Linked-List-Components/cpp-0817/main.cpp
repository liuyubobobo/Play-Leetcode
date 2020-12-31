/// Source : https://leetcode.com/problems/linked-list-components/description/
/// Author : liuyubobobo
/// Time   : 2018-04-14

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

// Definition for singly-linked list.
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

/// Grouping
/// Time Complexity: O(len(head) + len(g))
/// Space Complexity: O(len(g))
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {

        unordered_set<int> gSet;
        for(int num: G)
            gSet.insert(num);

        int res = 0, cur = 0;
        ListNode *curNode = head;
        while(curNode != NULL){
            if(gSet.find(curNode->val) != gSet.end()){
                if(cur == 0)
                    res ++;
                cur ++;
            }
            else
                cur = 0;

            curNode = curNode->next;
        }
        return res;
    }
};

int main() {

    int list1[4] = {0, 1, 2, 3};
    ListNode* head1 = createLinkedList(list1, 4);
    vector<int> G1 = {0, 1, 3};
    cout << Solution().numComponents(head1, G1) << endl;

    return 0;
}