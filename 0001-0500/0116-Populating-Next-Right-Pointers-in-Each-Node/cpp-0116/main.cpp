/// Source : https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/
/// Author : liuyubobobo
/// Time   : 2018-10-08
/// Updated: 2021-07-09

#include <iostream>
#include <queue>
#include <cassert>

using namespace std;


/// Using queue for BFS
/// Time Complexity: O(n)
/// Space Compelxity: O(n)

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

        if(!root) return root;

        queue<Node*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            int n = (1 << level);
            while(n --){
                Node* cur = q.front();
                q.pop();
                if(n)
                    cur->next = q.front();
                if(cur->left){
                    q.push(cur->left);
                    assert(cur->right);
                    q.push(cur->right);
                }
            }
            level ++;
        }
        return root;
    }
};


int main() {

    return 0;
}