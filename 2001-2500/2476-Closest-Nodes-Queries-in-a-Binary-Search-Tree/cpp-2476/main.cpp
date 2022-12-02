/// Source : https://leetcode.com/problems/closest-nodes-queries-in-a-binary-search-tree/description/
/// Author : liuyubobobo
/// Time   : 2022-11-28

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Binary Search
/// Time Complexity: O(nlogn)
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
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {

        vector<int> data;
        dfs(root, data);

        int q = queries.size();
        vector<vector<int>> res(q, {-1, -1});
        for(int i = 0; i < q; i ++){
            int e = queries[i];

            auto iter = upper_bound(data.begin(), data.end(), e);
            if(iter != data.begin()){
                iter --;
                res[i][0] = *iter;
            }

            iter = lower_bound(data.begin(), data.end(), e);
            if(iter != data.end()) res[i][1] = *iter;
        }
        return res;
    }

private:
    void dfs(TreeNode* node, vector<int>& data){
        if(!node) return;

        dfs(node->left, data);
        data.push_back(node->val);
        dfs(node->right, data);
    }
};


int main() {

    return 0;
}
