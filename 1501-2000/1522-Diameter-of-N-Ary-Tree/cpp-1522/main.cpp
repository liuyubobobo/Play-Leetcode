/// Source : https://leetcode.com/problems/diameter-of-n-ary-tree/
/// Author : liuyubobobo
/// Time   : 2020-10-15

#include <iostream>
#include <vector>

using namespace std;


/// DFS
/// Time Complexity: O(n)
/// Space Complexity: O(h)

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


class Solution {

private:
    int res;

public:
    int diameter(Node* root) {

        res = 0;
        dfs(root);
        return res;
    }

private:
    int dfs(Node* node){

        int first = 0, second = 0;
        for(Node* next: node->children){
            int t = 1 + dfs(next);
            if(t >= first) second = first, first = t;
            else if(t > second) second = t;
        }
        res = max(res, first + second);
        return first;
    }
};


int main() {

    return 0;
}
