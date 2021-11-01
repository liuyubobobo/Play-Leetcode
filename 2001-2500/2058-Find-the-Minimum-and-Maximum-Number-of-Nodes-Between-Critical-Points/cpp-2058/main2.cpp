/// Source : https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/
/// Author : liuyubobobo
/// Time   : 2021-10-31

#include <iostream>
#include <vector>

using namespace std;


/// One Pass in Linked List and O(1) Space
/// Time Compelxity: O(n)
/// Space Compelxity: O(1)

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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        int prev_node_val = head->val, prev_local = -1, first_local = -1, last_local = -1, min_dis = INT_MAX;
        ListNode* cur = head->next;
        for(int i = 1; cur->next; i ++, cur = cur->next){
            if((prev_node_val < cur->val && cur->val > cur->next->val) ||
               (prev_node_val > cur->val && cur->val < cur->next->val)){

                if(first_local == -1) first_local = i;
                last_local = max(last_local, i);
                if(prev_local != -1) min_dis = min(min_dis, i - prev_local);
                prev_local = i;
            }
            prev_node_val = cur->val;
        }

        if(min_dis == INT_MAX) return {-1, -1};
        return {min_dis, last_local - first_local};
    }
};


int main() {

    return 0;
}
