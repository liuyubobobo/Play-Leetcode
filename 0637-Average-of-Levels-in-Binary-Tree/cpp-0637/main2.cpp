/// Source : https://leetcode.com/problems/average-of-levels-in-binary-tree/description/
/// Author : liuyubobobo
/// Time   : 2018-06-03

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/// BFS, not use pairs
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {

        vector<double> res;
        if(root == NULL)
            return res;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){

            int num = q.size();
            long long sum = 0;
            for(int i = 0 ; i < num ; i ++){
                TreeNode* cur = q.front();
                q.pop();
                sum += (long long)cur->val;
                if(cur->left != NULL)
                    q.push(cur->left);
                if(cur->right != NULL)
                    q.push(cur->right);
            }
            res.push_back((double)sum / num);
        }

        return res;
    }
};


int main() {

    return 0;
}