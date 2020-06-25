/// Source : https://leetcode.com/problems/clone-binary-tree-with-random-pointer/
/// Author : liuyubobobo
/// Time   : 2020-06-24

#include <iostream>
#include <unordered_map>

using namespace std;


/// One Pass, Using HashMap and DFS
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
        return dfs(root);
    }

private:
    NodeCopy* dfs(Node* node){

        if(!node) return nullptr;
        if(map.count(node)) return map[node];

        NodeCopy* ret = new NodeCopy(node->val);
        map[node] = ret;

        ret->left = dfs(node->left);
        ret->right = dfs(node->right);
        ret->random = dfs(node->random);
        return ret;
    }
};


int main() {

    return 0;
}
