#include <iostream>
#include <unordered_map>

using namespace std;


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
    bool checkEqualTree(TreeNode* root) {

        unordered_map<TreeNode*, int> map;
        dfs_sum(root, map);

        return dfs(root, map, map[root]);
    }

private:
    bool dfs(TreeNode* node, const unordered_map<TreeNode*, int>& map, int sum){

        if(node == nullptr) return false;

        if(node->left && map.find(node->left)->second * 2 == sum) return true;
        if(node->right && map.find(node->right)->second * 2 == sum) return true;

        return dfs(node->left, map, sum) || dfs(node->right, map, sum);
    }

    int dfs_sum(TreeNode* node, unordered_map<TreeNode*, int>& map){

        if(node == nullptr) return 0;

        int res = node->val;
        res += dfs_sum(node->left, map);
        res += dfs_sum(node->right, map);
        map[node] = res;
        return res;
    }
};


int main() {

    return 0;
}
