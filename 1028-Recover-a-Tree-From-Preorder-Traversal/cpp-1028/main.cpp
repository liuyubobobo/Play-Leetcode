/// Source : https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/
/// Author : liuyubobobo
/// Time   : 2019-04-13

#include <iostream>
#include <cassert>

using namespace std;


/// Recursion
/// Time Complexity: O(|s|^2)
/// Space Complexity: O(|s|)

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* recoverFromPreorder(string S) {
        return build(S, 0);
    }

private:
    TreeNode* build(string s, int d){

        if(d >= s.size()) return NULL;

        assert(s[d] != '-');

        int num = first_number(s);
        TreeNode* root = new TreeNode(num);

        if(s.size()){
            int another = -1;
            for(int i = d + 1; i < s.size(); i ++)
                if(s[i] != '-' && ok(s, i + 1, d + 1)){
                    another = i + 1;
                    break;
                }

            if(another == -1) root->left = build(s, d + 1);
            else{
                root->left = build(s.substr(0, another), d + 1);
                root->right = build(s.substr(another), d + 1);
            }

        }
        return root;
    }

    int first_number(string& s){

        int digit = 0;
        for(; digit < s.size() && s[digit] == '-'; digit ++);

        int digit_end = digit + 1;
        for(;digit_end < s.size() && s[digit_end] != '-'; digit_end ++);

        string num_str = s.substr(digit, digit_end - digit);
        s = s.substr(digit_end);
        return atoi(num_str.c_str());
    }

    bool ok(const string& s, int start, int d){

        return ok(s.substr(start, d + 1), d);
    }

    bool ok(const string& s, int d){
        if(s.size() != d + 1) return false;
        for(int i = 0; i < s.size() - 1; i ++)
            if(s[i] != '-') return false;
        return s.back() != '-';
    }
};


int main() {

    Solution().recoverFromPreorder("1-401--349---90--88");

    return 0;
}