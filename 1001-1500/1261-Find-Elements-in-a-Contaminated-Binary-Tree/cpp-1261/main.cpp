/// Source : https://leetcode.com/contest/weekly-contest-163/problems/find-elements-in-a-contaminated-binary-tree/
/// Author : liuyubobobo
/// Time   : 2019-11-16

#include <iostream>
#include <set>

using namespace std;


/// DFS and Using Hash Set
/// Time Complexity: init: O(n)
///                  find: O(1)
/// Space Complexity: O(1)

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class FindElements {

private:
    set<int> vals;

public:
    FindElements(TreeNode* root) {
        if(root) dfs(root, 0);
    }

    bool find(int target) {
        return vals.find(target) != vals.end();
    }

private:
    void dfs(TreeNode* node, int val){

        node->val = val;
        vals.insert(val);
        if(node->left) dfs(node->left, val * 2 + 1);
        if(node->right) dfs(node->right, val * 2 + 2);
    }
};


int main() {
    
    return 0;
}