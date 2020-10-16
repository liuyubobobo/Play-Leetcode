/// Source : https://leetcode.com/problems/build-binary-expression-tree-from-infix-expression/
/// Author : liuyubobobo
/// Time   : 2020-09-27

#include <iostream>
#include <string>

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
    Node* expTree(string s) {
        return dfs(s, 0, s.size() - 1);
    }

private:
    Node* dfs(const string& s, int l, int r){

        if(l > r) return nullptr;
        if(l == r) return new Node(s[l]);

        if(s[l] != '('){
            if(s[l + 1] == '+' || s[l + 1] == '-')
                return new Node(s[l + 1], new Node(s[l]), dfs(s, l + 2, r));

            int stack = 0, end = -1;
            for(int i = l; i <= r; i ++){
                if(s[i] == '(') stack ++;
                else if(s[i] == ')') stack --;
                else if(s[i] == '+' || s[i] == '-')
                    if(!stack){end = i - 1; break;}
            }

            if(end == -1) return new Node(s[l + 1], new Node(s[l]), dfs(s, l + 2, r));
            return new Node(s[end + 1], dfs(s, l, end), dfs(s, end + 2, r));
        }
        else{
            int stack = 0, end = -1;
            for(int i = l; i <= r; i ++){
                if(s[i] == '(') stack ++;
                if(s[i] == ')') stack --;
                if(!stack){end = i; break;}
            }
            if(end + 1 <= r)
                return new Node(s[end + 1], dfs(s, l + 1, end - 1), dfs(s, end + 2, r));
            return dfs(s, l + 1, r - 1);
        }
    }
};


void inOrder(const Node* node){

    if(node == nullptr) return;
    inOrder(node->left);
    cout << node->val;
    inOrder(node->right);
}

int main() {

    Node* t1 = Solution().expTree("2-3/(5*2)+1");
    inOrder(t1);

    return 0;
}
