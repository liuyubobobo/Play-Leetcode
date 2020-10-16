#include <iostream>
#include <string>

using namespace std;


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

        if(s[r] != ')'){
            if(s[r - 1] == '+' || s[r - 1] == '-')
                return new Node(s[r - 1], dfs(s, l, r - 2), new Node(s[r]));

            int stack = 0, start = -1;
            for(int i = r; i >= l; i --){
                if(s[i] == ')') stack ++;
                else if(s[i] == '(') stack --;
                else if(s[i] == '+' || s[i] == '-'){
                    if(!stack){ start = i + 1; break;}
                }
            }

            if(start == -1) return new Node(s[r - 1], dfs(s, l, r - 2), new Node(s[r]));
            return new Node(s[start - 1], dfs(s, l, start - 2), dfs(s, start, r));
        }
        else{
            int stack = 0, start1 = -1, start2 = -1;
            for(int i = r; i >= l; i --){
                if(s[i] == ')') stack ++;
                if(s[i] == '(') stack --;
                if(!stack){
                    start = i; break
                }
            }
            if(start - 1 >= l)
                return new Node(s[start - 1], dfs(s, l, start - 2), dfs(s, start, r));
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
