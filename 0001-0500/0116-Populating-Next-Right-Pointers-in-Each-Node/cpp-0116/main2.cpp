/// Source : https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/
/// Author : liuyubobobo
/// Time   : 2018-10-08
/// Updated: 2021-07-09

#include <iostream>
#include <queue>
#include <cassert>

using namespace std;


/// DFS
/// Time Complexity: O(n)
/// Space Compelxity: O(logn)

/// Definition for binary tree with next pointer.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {

public:
    Node* connect(Node *root) {

        if(!root) return nullptr;
        dfs(root->left, root->right);

        connect(root->left);
        connect(root->right);
        return root;
    }

private:
    void dfs(Node* l, Node* r){

        if(l){
            l->next = r;
            dfs(l->right, r->left);
        }
    }
};


int main() {

    return 0;
}