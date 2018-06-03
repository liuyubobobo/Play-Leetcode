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

/// BFS, using pairs
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {

        vector<double> res;
        if(root == NULL)
            return res;

        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));

        long long sum = 0;
        int lastLevel = 0;
        int num = 0;
        while(!q.empty()){
            pair<TreeNode*, int> cur = q.front();
            q.pop();

            if(cur.second == lastLevel){
                sum += (long long)cur.first->val;
                num ++;
            }
            else{
                res.push_back((double)sum / num);
                sum = (long long)cur.first->val;
                num = 1;
                lastLevel = cur.second;
            }

            if(cur.first->left != NULL)
                q.push(make_pair(cur.first->left, cur.second + 1));
            if(cur.first->right != NULL)
                q.push(make_pair(cur.first->right, cur.second + 1));
        }
        if(num != 0)
            res.push_back((double)sum / num);

        return res;
    }
};


int main() {

    return 0;
}