/// Source : https://leetcode.com/problems/construct-binary-tree-from-string/
/// Author : liuyubobobo
/// Time   : 2021-03-15

#include <iostream>

using namespace std;


/// DFS
/// Time Complexity: O(n)
/// Space Complexity: O(n)

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* str2tree(string s) {

        return str2tree(s, 0, s.size() - 1);
    }

private:
    TreeNode* str2tree(const string& s, int l, int r){

        if(l > r) return NULL;

        if(s[l] == '('){
            assert(s[r] == ')');
            return str2tree(s, l + 1, r - 1);
        }

        int start = -1;
        for(int i = l; i <= r; i ++)
            if(s[i] == '('){
                start = i;
                break;
            }

        if(start == -1)
            return new TreeNode(atoi(s.substr(l, r - l + 1).c_str()));

        TreeNode* node = new TreeNode(atoi(s.substr(l, start - l).c_str()));

        int stack = 1;
        for(int i = start + 1; i <= r; i ++){
            if(s[i] == '(') stack ++;
            else if(s[i] == ')') stack --;

            if(stack == 0){
                assert(s[i] == ')');
                node->left = str2tree(s, start + 1, i - 1);
                node->right = str2tree(s, i + 1, r);

            }
        }
        return node;
    }
};


int main() {

    return 0;
}
