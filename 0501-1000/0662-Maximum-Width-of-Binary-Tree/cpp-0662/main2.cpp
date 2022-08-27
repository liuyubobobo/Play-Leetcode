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

        queue<tuple<TreeNode*, unsigned long long, int>> q;
        q.push({root, 0, 0});
        vector<unsigned long long> list;

        long long res = 0;
        int now_depth = 0;
        while(!q.empty()){
            TreeNode* node = get<0>(q.front());
            unsigned long long seq = get<1>(q.front());
            int d = get<2>(q.front());
            q.pop();

            if( d != now_depth ){
                now_depth = d;
                res = max(res, list.back() - list[0] + 1);
                list.clear();
            }
            list.push_back(seq);

            if(node->left){
                q.push({node->left, seq * 2 + 1, d + 1});
            }

            if(node->right){
                q.push({node->right, seq * 2 + 2, d + 1});
            }
        }

        res = max(res, list.back() - list[0] + 1);
        return res;
    }
};


int main() {

    return 0;
}
