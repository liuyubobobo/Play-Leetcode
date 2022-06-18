/// Source : https://leetcode.com/problems/most-frequent-subtree-sum/
/// Author : liuyubobobo
/// Time   : 2022-06-18

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// DFS
/// Time Compelxity: O(n)
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
    vector<int> findFrequentTreeSum(TreeNode* root) {

        map<int, int> f;
        dfs(root, f);

        vector<int> res;
        int max_f = 0;
        for(const pair<int, int>& p: f)
            if(p.second > max_f) res = {p.first}, max_f = p.second;
            else if(p.second == max_f) res.push_back(p.first);
        return res;
    }

private:
    int dfs(TreeNode* node, map<int, int>& f){

        if(!node) return 0;

        int res = node->val;
        res += dfs(node->left, f);
        res += dfs(node->right, f);
        f[res] ++;
        return res;
    }
};


int main() {

    return 0;
}
