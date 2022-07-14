/// Source : https://leetcode.com/problems/logical-or-of-two-binary-grids-represented-as-quad-trees/
/// Author : liuyubobobo
/// Time   : 2022-07-14

#include <iostream>

using namespace std;


/// DFS
/// Time Complexity: O(n)
/// Space Complexity: O(h)

/// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};


class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        return dfs(quadTree1, quadTree2);
    }

private:
    Node* dfs(Node* node1, Node* node2){

        if(node1->isLeaf && node2->isLeaf){
            return new Node(node1->val | node2->val, true);
        }

        Node* ret = new Node(0, false);
        ret->topLeft = dfs(node1->topLeft ? node1->topLeft : new Node(node1->val, true),
                           node2->topLeft ? node2->topLeft : new Node(node2->val, true));
        ret->topRight = dfs(node1->topRight ? node1->topRight : new Node(node1->val, true),
                            node2->topRight ? node2->topRight : new Node(node2->val, true));
        ret->bottomLeft = dfs(node1->bottomLeft ? node1->bottomLeft : new Node(node1->val, true),
                              node2->bottomLeft ? node2->bottomLeft : new Node(node2->val, true));
        ret->bottomRight = dfs(node1->bottomRight ? node1->bottomRight : new Node(node1->val, true),
                               node2->bottomRight ? node2->bottomRight : new Node(node2->val, true));

        if(ret->topLeft->isLeaf && ret->topRight->isLeaf && ret->bottomLeft->isLeaf && ret->bottomRight->isLeaf &&
           same(ret->topLeft->val, ret->topRight->val, ret->bottomLeft->val, ret->bottomRight->val)){
            ret->val = ret->topLeft->val;
            ret->isLeaf = true;
            ret->topLeft = ret->topRight = ret->bottomLeft = ret->bottomRight = nullptr;
        }
        return ret;
    }

    bool same(bool a, bool b, bool c, bool d){
        return a == b && a == c && a == d;
    }
};


int main() {

    return 0;
}
