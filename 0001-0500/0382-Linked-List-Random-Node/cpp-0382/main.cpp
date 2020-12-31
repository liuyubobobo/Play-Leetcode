/// Source : https://leetcode.com/problems/linked-list-random-node/description/
/// Author : liuyubobobo
/// Time   : 2018-07-08

#include <iostream>

using namespace std;

/// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/// Reservoir Sampling
/// The detail of Resevoir Sampling can be seen here:
/// https://www.geeksforgeeks.org/reservoir-sampling/
///
/// Attention: Don't use srand in the random problem in Leetcode
/// Since it may lead to WA
/// I think the test code use its own random seed to verify your submitted code
///
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {

private:
    ListNode* head;

public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;
    }

    /** Returns a random node's value. */
    int getRandom() {

        int res = head->val;
        ListNode* cur = head->next;
        int index = 1;

        // srand(time(NULL));
        while(cur != NULL){
            int rnd = rand() % (index + 1);
            if(rnd == 0)
                res = cur->val;

            cur = cur->next;
            index ++;
        }

        return res;
    }
};


int main() {

    return 0;
}