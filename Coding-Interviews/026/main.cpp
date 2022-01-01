/// Source : https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof/
/// Author : liuyubobobo
/// Time   : 2022-01-01

#include <iostream>

using namespace std;


/// DFS
/// Time Complexity: O(|A| * |B|)
/// Space Complexity: O(h)

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* l, TreeNode* r): val(x), left(l), right(r){}
};

class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (!B) return false;
        return is_contain(A, B);
    }

private:
    bool is_contain(TreeNode* A, TreeNode* B){

        if (!A) return false;

        if (A->val == B->val && is_equal(A->left, B->left) && is_equal(A->right, B->right))
            return true;

        return is_contain(A->left, B) || is_contain (A->right, B);
    }

    bool is_equal(TreeNode* A, TreeNode* B) {

        if(!B) return true;
        if(!A) return false;
        return A->val == B->val && is_equal(A->left, B->left) && is_equal(A->right, B->right);
    }
};


int main() {

    TreeNode* left_node1 = new TreeNode(0, new TreeNode(-4), new TreeNode(-3));
    TreeNode* right_node1 = new TreeNode(1);
    TreeNode* B1 = new TreeNode(1, new TreeNode(-4), nullptr);
    cout << Solution().isSubStructure(new TreeNode(1, left_node1, right_node1), B1) << endl;
    // false

    TreeNode* left_node2 = new TreeNode(12, new TreeNode(8), new TreeNode(3));
    TreeNode* right_node2 = new TreeNode(6, new TreeNode(11), nullptr);
    TreeNode* B2 = new TreeNode(10, new TreeNode(12, new TreeNode(8), nullptr), new TreeNode(6));
    cout << Solution().isSubStructure(new TreeNode(10, left_node2, right_node2), B2) << endl;
    // true

    return 0;
}
