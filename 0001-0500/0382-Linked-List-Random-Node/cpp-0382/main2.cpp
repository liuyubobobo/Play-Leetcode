/// Source : https://leetcode.com/problems/linked-list-random-node/description/
/// Author : liuyubobobo
/// Time   : 2018-07-09

#include <iostream>
#include <vector>
#include <cassert>

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
/// This code is based on using more general reservor sampling algorithm
/// where k = 1
///
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

private:
    vector<int> nums;

public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        nums.clear();
        while(head){
            nums.push_back(head->val);
            head = head->next;
        }
    }

    /** Returns a random node's value. */
    int getRandom() {
        // In this problem, k == 1
        return reservorSampling(nums, 1)[0];
    }

private:
    /// General Reservor Sampling Algorithm
    /// From vector nums, randomly pick k elements:)
    vector<int> reservorSampling(const vector<int>& nums, int k){

        assert(k >= 1 && k <= nums.size());
        vector<int> res(nums.begin(), nums.begin() + k);

        for(int i = k ; i < nums.size() ; i ++){
            int index = rand() % (i + 1);
            if(index < k)
                res[index] = nums[i];
        }

        return res;
    }
};


int main() {

    return 0;
}