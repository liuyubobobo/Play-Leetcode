/// Source : https://leetcode.com/problems/two-sum/description/
/// Author : liuyubobobo
/// Time   : 2018-08-21

#include <iostream>
#include <vector>

using namespace std;

/// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class ListOp{

public:
    // 根据n个元素的数组arr创建一个链表, 并返回链表的头
    static ListNode* createLinkedList(const vector<int>& arr){

        if(arr.size() == 0)
            return NULL;

        ListNode* head = new ListNode(arr[0]);
        ListNode* curNode = head;
        for(int i = 1 ; i < arr.size() ; i ++){
            curNode->next = new ListNode(arr[i]);
            curNode = curNode->next;
        }
        return head;
    }

    // 打印以head为头结点的链表信息内容
    static void printLinkedList(ListNode* head){

        ListNode* curNode = head;
        while(curNode){
            cout << curNode->val << " -> ";
            curNode = curNode->next;
        }
        cout << "NULL" << endl;
    }

    // 释放以head为头结点的链表空间
    static void deleteLinkedList(ListNode* head){

        ListNode* curNode = head;
        while(curNode){
            ListNode* delNode = curNode;
            curNode = curNode->next;
            delete delNode;
        }
    }
};


/// Merge Sort Top Down
/// Time Complexity: O(nlogn)
/// Space Complexity: O(logn)
class Solution {
public:
    ListNode* sortList(ListNode* head) {

        if(head == NULL || head->next == NULL)
            return head;

        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* head2 = slow->next;
        slow->next = NULL;
        head = sortList(head);
        head2 = sortList(head2);
        return merge(head, head2);
    }

private:
    ListNode* merge(ListNode* a, ListNode* b){

        ListNode* dummyHead = new ListNode(-1);
        ListNode *p1 = a, *p2 = b, *p = dummyHead;
        while(p1 && p2)
            if(p1->val < p2->val){
                p->next = p1;
                p1 = p1->next;
                p = p->next;
                p->next = NULL;
            }
            else{
                p->next = p2;
                p2 = p2->next;
                p = p->next;
                p->next = NULL;
            }
        if(p1) p->next = p1;
        if(p2) p->next = p2;

        ListNode* ret = dummyHead->next;
        delete dummyHead;
        return ret;
    }
};


int main() {

    vector<int> arr = {4, 2, 1, 3};
    ListNode* head = Solution().sortList(ListOp::createLinkedList(arr));
    ListOp::printLinkedList(head);
    ListOp::deleteLinkedList(head);

    return 0;
}