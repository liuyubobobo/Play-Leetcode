/// Source : https://leetcode.com/problems/clone-binary-tree-with-random-pointer/
/// Author : liuyubobobo
/// Time   : 2020-06-24

#include <iostream>
#include <unordered_map>

using namespace std;


/// Two Pass, Using HashMap and DFS
/// Time Complexity: O(n)
/// Space Complexity: O(n)

/// Definition for a Node.
struct Node {
    int val;
    Node *left;
    Node *right;
    Node *random;
    Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
    Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
};

struct NodeCopy {
    int val;
    NodeCopy *left;
    NodeCopy *right;
    NodeCopy *random;
    NodeCopy() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
    NodeCopy(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
    NodeCopy(int x, NodeCopy *left, NodeCopy *right, NodeCopy *random) : val(x), left(left), right(right), random(random) {}
};


class Solution {

private:
    unordered_map<Node*, NodeCopy*> map;

public:
    NodeCopy* copyRandomBinaryTree(Node* root) {

        NodeCopy* ret = dfs(root);
        set_rand_pointer(root, ret);
        return ret;
    }

private:
    void set_rand_pointer(Node* node, NodeCopy* nodecopy){

        if(!node) return;
        nodecopy->random = map[node->random];
        set_rand_pointer(node->left, nodecopy->left);
        set_rand_pointer(node->right, nodecopy->right);
    }

    NodeCopy* dfs(Node* node){

        if(!node) return nullptr;
        NodeCopy* ret = new NodeCopy(node->val, dfs(node->left), dfs(node->right), nullptr);
        map[node] = ret;
        return ret;
    }
};


int main() {

    return 0;
}
