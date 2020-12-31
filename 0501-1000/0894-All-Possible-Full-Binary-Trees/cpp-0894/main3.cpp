/// Source : https://leetcode.com/problems/all-possible-full-binary-trees/description/
/// Author : liuyubobobo
/// Time   : 2018-08-25

#include <iostream>
#include <vector>

using namespace std;


/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/// Dynamic Programming
/// Time Complexity: O(n^4), Actually, maybe lower than that:)
/// Space Complexity: O(n^4)
class Solution {

private:
    TreeNode* root;

public:
    vector<TreeNode*> allPossibleFBT(int N) {

        vector<TreeNode*> res;
        if(N % 2 == 0)
            return res;

        if(N == 1)
            return {new TreeNode(0)};

        vector<vector<TreeNode*>> dp(N + 1);
        dp[1] = {new TreeNode(0)};
        for(int i = 3; i <= N; i += 2){
            // total i nodes
            for(int j = 1; j <= i - 1; j += 2){
                // left: j nodes, right: i - 1 - j nodes
                for(TreeNode* left: dp[j])
                    for(TreeNode* right: dp[i - 1 - j]) {
                        TreeNode* root = new TreeNode(0);
                        root->left = left;
                        root->right = right;
                        dp[i].push_back(root);
                    }
            }
        }
        return dp[N];
    }
};


int main() {

    return 0;
}