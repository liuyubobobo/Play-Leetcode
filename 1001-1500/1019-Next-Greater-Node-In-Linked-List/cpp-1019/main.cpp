/// Source : https://leetcode.com/problems/next-greater-node-in-linked-list/
/// Author : liuyubobobo
/// Time   : 2019-03-30

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


/// Using Stack
/// Time Complexity: O(n)
/// Space Complexity: O(n)

/// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {

        vector<int> nums = get_nums(head);
        return nextLargerNodes(nums);
    }

    vector<int> nextLargerNodes(const vector<int>& nums){

        stack<int> stack;
        vector<int> res(nums.size(), 0);
        for(int i = 0; i < nums.size(); i ++){

            while(!stack.empty() && nums[stack.top()] < nums[i])
                res[stack.top()] = nums[i], stack.pop();

            stack.push(i);
        }
        return res;
    }

private:
    vector<int> get_nums(ListNode* head){

        vector<int> res;

        ListNode* cur = head;
        while(cur){
            res.push_back(cur->val);
            cur = cur->next;
        }
        return res;
    }
};


void print_vec(const vector<int>& vec){
    for(int e: vec) cout << e << " ";
    cout << endl;
}

int main() {

    vector<int> nums1 = {2, 1, 5};
    print_vec(Solution().nextLargerNodes(nums1));

    vector<int> nums2 = {2, 7, 4, 3, 5};
    print_vec(Solution().nextLargerNodes(nums2));

    vector<int> nums3 = {1,7,5,1,9,2,5,1};
    print_vec(Solution().nextLargerNodes(nums3));


    return 0;
}