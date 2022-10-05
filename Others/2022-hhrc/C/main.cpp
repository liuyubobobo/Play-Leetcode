/// Source : https://leetcode.cn/contest/hhrc2022/problems/VAc7h3/
/// Author : liuyubobobo
/// Time   : 2022-10-03

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Hash
/// Time Complexity: O(n)
/// Space Complexity: O(n^2)

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
    vector<TreeNode*> lightDistribution(TreeNode* root) {

        map<string, vector<TreeNode*>> m;
        dfs(root, m);

        vector<TreeNode*> res;
        for(const pair<string, vector<TreeNode*>>& p: m)
            if(p.second.size() > 1) res.push_back(p.second[0]);
        return res;
    }

private:
    string dfs(TreeNode* node, map<string, vector<TreeNode*>>& m){

        if(node == nullptr) return "(null)";

        string hash = "(" + to_string(node->val);
        hash += dfs(node->left, m);
        hash += dfs(node->right, m);
        hash += ")";

        m[hash].push_back(node);
        return hash;
    }
};


int main() {

    return 0;
}
