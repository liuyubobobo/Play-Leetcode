/// Source : https://leetcode.com/problems/complete-binary-tree-inserter/description/
/// Author : liuyubobobo
/// Time   : 2018-10-06

#include <iostream>

using namespace std;


/// Inspiring by Heap, using an integer to present every node, starting from 1
/// Then, we know in a complete tree, if the node's id is x
/// It's left child's id would be 2*x, it's right child's id would be 2*x + 1
///
/// Time Complexity: init: O(n)
///                  insert: O((logn)^2)
///                  get_root: O(1)
/// Space Complexity: O(1)

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class CBTInserter {

private:
    int nextID;
    TreeNode* root;

public:
    CBTInserter(TreeNode* root) {
        this->root = root;
        nextID = getNodeNumber(root) + 1;
    }

    int insert(int v) {

        TreeNode* p = root;
        int pID = 1;
        while(true){
            if(nextID == 2 * pID){
                p->left = new TreeNode(v);
                break;
            }
            else if(nextID == 2 * pID + 1){
                p->right = new TreeNode(v);
                break;
            }

            int id = nextID;
            while(id / 2 != pID)
                id /= 2;

            if(id == 2 * pID)
                p = p->left;
            else
                p = p->right;
            pID = id;
        }

        nextID ++;
        return p->val;
    }

    TreeNode* get_root() {
        return root;
    }

private:
    int getNodeNumber(TreeNode* node){

        if(!node)
            return 0;

        return 1 + getNodeNumber(node->left) + getNodeNumber(node->right);
    }
};


int main() {

    return 0;
}