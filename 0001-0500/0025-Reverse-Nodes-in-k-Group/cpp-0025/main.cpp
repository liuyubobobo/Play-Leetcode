/// Source : https://leetcode.com/problems/reverse-nodes-in-k-group/description/
/// Author : liuyubobobo
/// Time   : 2019-08-09

#include <iostream>
#include <vector>

using namespace std;


/// Linear Scan and Recursive Reverse
/// Time Complexity: O(n)
/// Space Complexity: O(k)

/// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;

        ListNode* pre = dummyHead;
        while(pre && pre->next){

            ListNode* end = pre;
            int i;
            for(i = 0; i < k && end->next; i ++)
                end = end->next;

            if(i != k) break;

            ListNode* next = end->next;

            // reverse from pre->next to end
            ListNode* rhead = reverse(pre->next, end);

            ListNode* tail = pre->next;
            pre->next = rhead;
            tail->next = next;
            pre = tail;
        }

        ListNode* ret = dummyHead->next;
        delete dummyHead;
        return ret;
    }

private:
    ListNode* reverse(ListNode* head, ListNode* end){

        if(head == end) return head;

        ListNode* rhead = reverse(head->next, end);
        head->next->next = head;
        return rhead;
    }
};


/// LinkedList 测试辅助函数

// 根据n个元素的数组arr创建一个链表, 并返回链表的头
ListNode* createLinkedList(const vector<int>& arr){

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
void printLinkedList(ListNode* head){

    ListNode* curNode = head;
    while(curNode != NULL){
        cout << curNode->val << " -> ";
        curNode = curNode->next;
    }

    cout << "NULL" << endl;

    return;
}

// 释放以head为头结点的链表空间
void deleteLinkedList(ListNode* head){

    ListNode* curNode = head;
    while(curNode != NULL){
        ListNode* delNode = curNode;
        curNode = curNode->next;
        delete delNode;
    }

    return;
}


int main() {

    vector<int> arr1 = {1, 2, 3, 4, 5};
    ListNode* res1 = Solution().reverseKGroup(createLinkedList(arr1), 3);
    printLinkedList(res1);
    deleteLinkedList(res1);

    return 0;
}