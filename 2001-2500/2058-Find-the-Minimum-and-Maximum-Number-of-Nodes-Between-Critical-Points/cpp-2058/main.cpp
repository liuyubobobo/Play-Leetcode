/// Source : https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/
/// Author : liuyubobobo
/// Time   : 2021-10-30

#include <iostream>
#include <vector>

using namespace std;


/// Using Array
/// Time Compelxity: O(n)
/// Space Compelxity: O(n)

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

        vector<int> data;
        while(head){
            data.push_back(head->val);
            head = head->next;
        }

        int n = data.size();
        vector<int> pos;
        for(int i = 1; i + 1 < n; i ++){
            if(data[i - 1] < data[i] && data[i] > data[i + 1])
                pos.push_back(i);
            else if(data[i - 1] > data[i] && data[i] < data[i + 1])
                pos.push_back(i);
        }

        if(pos.size() < 2) return {-1, -1};

        int min_dis = INT_MAX;
        for(int i = 1; i < pos.size(); i ++)
            min_dis = min(min_dis, pos[i] - pos[i - 1]);
        return {min_dis, pos.back() - pos[0]};
    }
};


int main() {

    return 0;
}
