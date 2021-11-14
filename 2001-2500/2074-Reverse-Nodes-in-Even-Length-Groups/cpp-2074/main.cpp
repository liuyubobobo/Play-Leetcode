/// Source : https://leetcode.com/problems/reverse-nodes-in-even-length-groups/
/// Author : liuyubobobo
/// Time   : 2021-11-13

#include <iostream>
#include <vector>

using namespace std;


/// Using Array to store
/// Time Complexity: O(n)
/// Space Complexity: O(n)

/// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {

        vector<int> data;
        ListNode* cur = head;
        while(cur) data.push_back(cur->val), cur = cur->next;

        int n = data.size();
        int len = 1, index = 0;
        while(index < n){
            int start = index, end = min(index + len - 1, n - 1);
            if((end - start + 1) % 2 == 0)
                reverse(data, start, end);
            index = end + 1;
            len ++;
        }

        ListNode* dummy = new ListNode(-1);
        cur = dummy;
        for(int i = 0; i < n; i ++)
            cur->next = new ListNode(data[i]), cur = cur->next;
        return dummy->next;
    }

private:
    void reverse(vector<int>& data, int start, int end){

        int l = start, r = end;
        while(l < r) swap(data[l], data[r]), l ++, r --;
    }
};


int main() {

    return 0;
}
