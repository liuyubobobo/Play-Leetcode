/// Source : https://leetcode.com/problems/middle-of-the-linked-list/description/
/// Author : liuyubobobo
/// Time   : 2018-08-02

#include <iostream>
#include <vector>

using namespace std;


/// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


/// Using Array
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        vector<ListNode*> nums;

        ListNode* cur = head;
        while(cur != NULL)
            nums.push_back(cur), cur = cur->next;

        return nums[nums.size() / 2];
    }
};


int main() {

    return 0;
}