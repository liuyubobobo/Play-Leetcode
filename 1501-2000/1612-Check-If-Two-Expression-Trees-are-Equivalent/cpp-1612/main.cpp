/// Source : https://leetcode.com/problems/check-if-two-expression-trees-are-equivalent/
/// Author : liuyubobobo
/// Time   : 2020-10-15

#include <iostream>
#include <unordered_map>

using namespace std;


/// DFS
/// Time Complexity: O(n)
/// Space Complexity: O(n)

/// Definition for a binary tree node.
struct Node {
    char val;
    Node *left;
    Node *right;
    Node() : val(' '), left(nullptr), right(nullptr) {}
    Node(char x) : val(x), left(nullptr), right(nullptr) {}
    Node(char x, Node *left, Node *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool checkEquivalence(Node* root1, Node* root2) {

        unordered_map<char, int> set1, set2;
        dfs(root1, set1); dfs(root2, set2);

        for(const pair<char, int>& p: set1){
            if(!set2.count(p.first) || set2[p.first] != p.second) return false;
            set2.erase(p.first);
        }
        return set2.empty();
    }

private:
    void dfs(Node* node, unordered_map<char, int>& set){

        if(!node) return;
        if(!node->left && !node->right) set[node->val] ++;
        dfs(node->left, set);
        dfs(node->right, set);
    }
};


int main() {

    return 0;
}
