/// Source : https://leetcode.com/problems/all-possible-full-binary-trees/description/
/// Author : liuyubobobo
/// Time   : 2018-08-26

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/// Memory Search
/// Time Complexity: O(n^4), Actually, maybe lower than that:)
/// Space Complexity: O(n^4)
class Solution {

private:
    TreeNode* root;

public:
    vector<TreeNode*> allPossibleFBT(int N){
        if(N % 2 == 0)
            return {};

        unordered_map<int, vector<TreeNode*>> memo;
        return allPossibleFBT(N, memo);
    }

    vector<TreeNode*> allPossibleFBT(int N, unordered_map<int, vector<TreeNode*>>& memo) {

        if(memo.find(N) != memo.end())
            return memo[N];

        if(N == 1)
            return memo[1] = {new TreeNode(0)};

        for(int i = 1; i < N; i += 2){
            vector<TreeNode*> left_vec = allPossibleFBT(i);
            vector<TreeNode*> right_vec = allPossibleFBT(N - 1 - i);
            for(TreeNode* left: left_vec)
                for(TreeNode* right: right_vec){
                    TreeNode* root = new TreeNode(0);
                    root->left = left;
                    root->right = right;
                    memo[N].push_back(root);
                }
        }
        return memo[N];
    }
};


int main() {

    Solution().allPossibleFBT(7);

    return 0;
}