/// Source : https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/
/// Author : liuyubobobo
/// Time   : 2022-01-08

#include <iostream>
#include <vector>

using namespace std;


/// Using Array
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
    int pairSum(ListNode* head) {

        vector<int> data;
        for(ListNode* node = head; node; node = node->next)
            data.push_back(node->val);

        int n = data.size();
        int res = 0;
        for(int i = 0; i + i < n; i ++)
            res = max(res, data[i] + data[n - i - 1]);
        return res;
    }
};


int main() {

    return 0;
}
