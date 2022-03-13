/// Source : https://leetcode-cn.com/contest/cnunionpay-2022spring/problems/D7rekZ/
/// Author : liuyubobobo
/// Time   : 2022-03-13

#include <iostream>
#include <vector>

using namespace std;


/// Greedy
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
    bool isPalindrome(ListNode* head) {

        vector<int> v;
        ListNode* cur = head;
        while(cur){
            v.push_back(cur->val);
            cur = cur->next;
        }

        int n = v.size();
        int l = 0, r = n - 1;
        while(l < r && v[l] == v[r]) l ++, r --;

        if(l >= r) return true;

        return is_palindrome(v, l, r - 1) || is_palindrome(v, l + 1, r);
    }

private:
    bool is_palindrome(const vector<int>& v, int l, int r){

        int i = l, j = r;
        while(i < j){
            if(v[i] != v[j]) return false;
            i ++, j --;
        }
        return true;
    }
};


int main() {

    return 0;
}
