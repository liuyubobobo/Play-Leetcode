/// Source : https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/
/// Author : liuyubobobo
/// Time   : 2019-08-18
/// Updated: 2022-06-16

#include <iostream>
#include <queue>
#include <climits>
#include <cassert>

using namespace std;


/// BFS
/// Time Complexity: O(n)
/// Space Complexity: O(n)

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

public:
    int maxLevelSum(TreeNode* root) {

        if(!root) return 0;

        queue<TreeNode*> q;
        int best = INT_MIN, res = 0, cur_level = 0;
        q.push(root);
        while(!q.empty()){

            cur_level ++;
            queue<TreeNode*> q2;
            int sum = 0;
            while(!q.empty()){
                TreeNode* cur = q.front(); q.pop(); assert(cur);
                sum += cur->val;
                if(cur->left) q2.push(cur->left);
                if(cur->right) q2.push(cur->right);
            }

            // cout << cur_level << ' ' << sum << '\n';
            if(sum > best) best = sum, res = cur_level;

            q = q2;
        }
        return res;
    }
};


int main() {

    return 0;
}