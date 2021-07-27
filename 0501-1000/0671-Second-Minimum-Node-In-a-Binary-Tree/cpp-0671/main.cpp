#include <iostream>
#include <set>

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
    int findSecondMinimumValue(TreeNode* root) {

        set<int> set;
        dfs(root, set);

        if(set.size() == 1) return -1;

        auto iter = set.begin();
        iter ++;
        return *iter;
    }

private:
    void dfs(TreeNode* node, set<int>& set){

        if(!node) return;

        set.insert(node->val);
        dfs(node->left, set);
        dfs(node->right, set);
    }
};


int main() {

    return 0;
}
