/// Source : https://leetcode.com/problems/maximum-width-of-binary-tree/
/// Author : liuyubobobo
/// Time   : 2022-08-26

#include <iostream>
#include <vector>
#include <tuple>
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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {

        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        vector<unsigned long long> list;

        unsigned long long res = 0;
        while(!q.empty()){

            vector<pair<TreeNode*, unsigned long long>> v;
            while(!q.empty()){
                TreeNode* node = q.front().first;
                unsigned long long seq = q.front().second;
                q.pop();
                v.push_back({node, seq});
            }

            res = max(res, v.back().second - v.begin()->second + 1);

            for(const pair<TreeNode*, unsigned long long>& p: v){
                TreeNode* node = p.first;
                unsigned long long seq = p.second;

                if(node->left)
                    q.push({node->left, seq * 2});

                if(node->right)
                    q.push({node->right, seq * 2 + 1});
            }

        }
        return res;
    }
};


int main() {

    return 0;
}
