/// Source : https://leetcode.com/problems/reverse-nodes-in-k-group/description/
/// Author : liuyubobobo
/// Time   : 2018-10-02

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

        ListNode* cur = dummyHead;
        while(cur && cur->next){
            ListNode* tail = cur->next;

            ListNode* left;
            bool ok = false;
            cur->next = reverse(cur->next, k - 1, left, ok);
            tail->next = left;

            if(ok)
                cur = tail;
            else {
                tail = cur->next;
                cur->next = reverse(cur->next, k - 1, left, ok);
                tail->next = NULL;
                break;
            }
        }

        ListNode* ret = dummyHead->next;
        delete dummyHead;
        return ret;
    }

private:
    ListNode* reverse(ListNode* head, int index, ListNode* &left, bool& ok){

        if(index == 0 || !head->next){
            ok = index == 0;
            left = head->next;
            return head;
        }

        ListNode* tail = head->next;
        ListNode* ret = reverse(head->next, index - 1, left, ok);
        tail->next = head;
        return ret;
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