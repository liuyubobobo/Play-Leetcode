/// Source : https://leetcode.com/problems/encode-n-ary-tree-to-binary-tree/
/// Author : liuyubobobo
/// Time   : 2022-04-29

#include <iostream>
#include <vector>

using namespace std;


/// Left-Child Right-Sibling Representation
/// Time Complexity: O(n)
/// Space Complexity: O(1)

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

///Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    // Encodes an n-ary tree to a binary tree.
    TreeNode* encode(Node* node) {

        if(!node) return nullptr;

        TreeNode* ret = new TreeNode(node->val);

        if(node->children.size() == 0) return ret;

        vector<TreeNode*> v;
        for(Node* child_node: node->children) v.push_back(encode(child_node));

        for(int i = 1; i < v.size(); i ++) v[i - 1]->right = v[i];
        ret->left = v[0];
        return ret;
    }

    // Decodes your binary tree to an n-ary tree.
    Node* decode(TreeNode* node) {

        if(!node) return nullptr;

        Node* ret = new Node(node->val);
        if(!node->left) return ret;

        TreeNode* cur = node->left;
        vector<Node*> v;
        while(cur){
            v.push_back(decode(cur));
            cur = cur->right;
        }
        ret->children = v;
        return ret;
    }
};


int main() {

    return 0;
}
