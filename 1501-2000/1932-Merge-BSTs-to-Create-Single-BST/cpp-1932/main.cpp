/// Source : https://leetcode.com/problems/merge-bsts-to-create-single-bst/
/// Author : liuyubobobo
/// Time   : 2021-07-11

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

using namespace std;


/// Simulation
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

        unordered_map<int, vector<TreeNode*>> f;
        unordered_set<TreeNode*> roots;
        unordered_map<TreeNode*, TreeNode*> to_root;
        for(TreeNode* node: trees){
            dfs(node, f, to_root, node);
            roots.insert(node);
        }

        int cnt = 0;
        for(const pair<int, vector<TreeNode*>>& p: f){
            if(p.second.size() > 2) return nullptr;
            else if(p.second.size() == 2) cnt ++;
        }

        if(cnt + 1 != trees.size()) return nullptr;

        TreeNode* root = build(roots, f, to_root);

        if(!root) return nullptr;
        return is_bst(root, INT_MIN, INT_MAX) ? root : nullptr;
    }

private:
    TreeNode* build(unordered_set<TreeNode*>& roots,
                    unordered_map<int, vector<TreeNode*>>& f,
                    unordered_map<TreeNode*, TreeNode*>& to_root){

        for(const pair<int, vector<TreeNode*>>& p: f)
            if(p.second.size() == 2){

                TreeNode *a = p.second[0], *b = p.second[1];

                TreeNode *root, *leaf;
                if(roots.count(a) && is_leaf(b)) root = a, leaf = b;
                else if(roots.count(b) && is_leaf(a)) root = b, leaf = a;
                else return nullptr;

                if(to_root[root] == to_root[leaf]) return nullptr;

                leaf->left = root->left;
                leaf->right = root->right;

                if(leaf->left) to_root[leaf->left] = to_root[leaf];
                if(leaf->right) to_root[leaf->right] = to_root[leaf];
                roots.erase(root);
            }
//            else assert(p.second.size() == 1);

        return roots.size() == 1 ? *roots.begin() : nullptr;
    }

    bool is_bst(TreeNode* node, int a, int b){

        if(!node) return true;

        if(!(a <= node->val && node->val <= b)) return false;

        return is_bst(node->left, a, node->val - 1) && is_bst(node->right, node->val + 1, b);
    }

    void dfs(TreeNode* node, unordered_map<int, vector<TreeNode*>>& f,
             unordered_map<TreeNode*, TreeNode*>& to_root, TreeNode* root){

        if(!node) return;

        f[node->val].push_back(node);
        to_root[node] = root;

        dfs(node->left, f, to_root, root);
        dfs(node->right, f, to_root, root);
    }

    bool is_leaf(TreeNode* node){
        return !node->left && !node->right;
    }
};


int main() {

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
