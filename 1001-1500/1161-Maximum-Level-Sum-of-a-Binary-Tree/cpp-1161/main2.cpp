/// Source : https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/
/// Author : liuyubobobo
/// Time   : 2019-08-18

#include <iostream>
#include <queue>

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

        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 1));
        int sum = INT_MIN, record_level = 0, best = INT_MIN, res = 0;
        while(!q.empty()){
            TreeNode* curNode = q.front().first;
            int cur_level = q.front().second;
            q.pop();

            if(cur_level != record_level){
                if(sum > best)
                    best = sum, res = record_level;
                sum = 0, record_level = cur_level;
            }

            sum += curNode->val;
            if(curNode->left) q.push(make_pair(curNode->left, cur_level + 1));
            if(curNode->right) q.push(make_pair(curNode->right, cur_level + 1));
        }
        return sum > best ? record_level : res;
    }
};


int main() {

    return 0;
}