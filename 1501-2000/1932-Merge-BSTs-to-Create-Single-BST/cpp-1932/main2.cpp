/// Source : https://leetcode.com/problems/merge-bsts-to-create-single-bst/
/// Author : liuyubobobo
/// Time   : 2021-07-11

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
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
    TreeNode* canMerge(vector<TreeNode*>& trees) {

        unordered_map<int, int> f;
        unordered_map<int, TreeNode*> roots;
        for(TreeNode* node: trees){
            dfs(node, f);
            roots[node->val] = node;
        }

        int cnt = 0;
        for(const pair<int, int>& p: f){
            if(p.second > 2) return nullptr;
            else if(p.second == 2) cnt ++;
        }

        if(cnt + 1 != trees.size()) return nullptr;

        TreeNode* root = nullptr;
        for(TreeNode* node: trees)
            if(f[node->val] == 1){
                if(root) return nullptr;
                root = node;
            }

        root = build(roots, root);

        if(!root) return nullptr;
        return is_bst(root, INT_MIN, INT_MAX) ? root : nullptr;
    }

private:
    TreeNode* build(unordered_map<int, TreeNode*>& roots, TreeNode* root){

        queue<TreeNode*> q;
        if(is_leaf(root)) q.push(root);
        else{
            if(root->left) q.push(root->left);
            if(root->right) q.push(root->right);
        }
        roots.erase(root->val);

        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();

            if(roots.count(cur->val)){
                TreeNode* node = roots[cur->val];
                cur->left = node->left;
                cur->right = node->right;

                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);

                roots.erase(cur->val);
            }
        }
        return roots.empty() ? root : nullptr;
    }

    bool is_bst(TreeNode* node, int a, int b){

        if(!node) return true;

        if(!(a <= node->val && node->val <= b)) return false;

        return is_bst(node->left, a, node->val - 1) && is_bst(node->right, node->val + 1, b);
    }

    void dfs(TreeNode* node, unordered_map<int, int>& f){

        if(!node) return;

        f[node->val] ++;

        dfs(node->left, f);
        dfs(node->right, f);
    }

    bool is_leaf(TreeNode* node){
        return !node->left && !node->right;
    }
};


int main() {

    vector<TreeNode*> trees0 = {new TreeNode(7)};
    cout << Solution().canMerge(trees0) << endl;
    // 7

    vector<TreeNode*> trees1 = {new TreeNode(1, nullptr, new TreeNode(3)),
                                new TreeNode(3, new TreeNode(1), nullptr),
                                new TreeNode(4, new TreeNode(2), nullptr)};
    cout << Solution().canMerge(trees1) << endl;
    // null

    vector<TreeNode*> trees2 = {new TreeNode(5, new TreeNode(1), nullptr),
                                new TreeNode(1, nullptr, new TreeNode(4)),
                                new TreeNode(4, new TreeNode(2), nullptr),
                                new TreeNode(2, nullptr, new TreeNode(3))};
    cout << Solution().canMerge(trees2) << endl;
    // 5

    return 0;
}
