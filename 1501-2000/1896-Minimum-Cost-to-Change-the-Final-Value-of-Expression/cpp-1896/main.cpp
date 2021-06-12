/// Source : https://leetcode.com/problems/minimum-cost-to-change-the-final-value-of-expression/
/// Author : liuyubobobo
/// Time   : 2021-06-12

#include <iostream>
#include <stack>
#include <vector>
#include <cassert>
#include <unordered_map>

using namespace std;


/// Build Expression Tree + Memory Search
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

private:
    class Node{
    public:
        char op;
        int val;
        Node *left, *right;

        Node(char op, int val, Node* left, Node* right) : op(op), val(val), left(left), right(right){}
        Node(char op, int val) : Node(op, val, nullptr, nullptr){}
        Node(char op) : Node(op, -1, nullptr, nullptr){}
    };

public:
    int minOperationsToFlip(string expression) {

        int n = expression.size();
        stack<int> stack;
        vector<int> match(n, -1);
        for(int i = 0; i < n; i ++)
            if(expression[i] == '(')
                stack.push(i);
            else if(expression[i] == ')'){
                assert(!stack.empty());
                match[i] = stack.top();
                match[stack.top()] = i;
                stack.pop();
            }
        assert(stack.empty());

        Node* root = build(expression, 0, n - 1, match);

        vector<unordered_map<Node*, int>> dp(2);
        return dfs(root, 1 - root->val, dp);
    }

private:
    int dfs(Node* node, int changeto, vector<unordered_map<Node*, int>>& dp){

        if(node->op == 'v') return node->val != changeto;
        if(dp[changeto].count(node)) return dp[changeto][node];

        if(node->val == changeto) return 0;

        int res = INT_MAX;
        if(changeto == 0){
            // 0 | 0
            res = min(res, (node->op != '|') + dfs(node->left, 0, dp) + dfs(node->right, 0, dp));

            // 0 & 0
            res = min(res, (node->op != '&') + dfs(node->left, 0, dp) + dfs(node->right, 0, dp));

            // 0 & 1
            res = min(res, (node->op != '&') + dfs(node->left, 0, dp) + dfs(node->right, 1, dp));

            // 1 & 0
            res = min(res, (node->op != '&') + dfs(node->left, 1, dp) + dfs(node->right, 0, dp));
        }
        else{ // changeto == 1
            // 0 | 1
            res = min(res, (node->op != '|') + dfs(node->left, 0, dp) + dfs(node->right, 1, dp));

            // 1 | 0
            res = min(res, (node->op != '|') + dfs(node->left, 1, dp) + dfs(node->right, 0, dp));

            // 1 | 1
            res = min(res, (node->op != '|') + dfs(node->left, 1, dp) + dfs(node->right, 1, dp));

            // 1 & 1
            res = min(res, (node->op != '&') + dfs(node->left, 1, dp) + dfs(node->right, 1, dp));
        }
        return dp[changeto][node] = res;
    }

    Node* build(const string& exp, int l, int r, const vector<int>& match){

        if(l == r){
//            assert(isdigit(exp[l]));
            return new Node('v', exp[l] - '0');
        }

        if(exp[r] == ')'){
            if(match[r] == l) return build(exp, l + 1, r - 1, match);

            Node* right = build(exp, match[r], r, match);
//            assert(exp[match[r] - 1] == '|' || exp[match[r] - 1] == '&');
//            assert(l <= exp[match[r] - 2]);
            Node* left = build(exp, l, match[r] - 2, match);
            return new Node(exp[match[r] - 1],
                            exp[match[r] - 1] == '|' ? (left->val | right->val) : (left->val & right->val),
                            left, right);
        }

//        assert(isdigit(exp[r]));
//        assert(exp[r - 1] == '&' || exp[r - 1] == '|');
//        assert(l <= r - 2);
        Node* right = new Node('v', exp[r] - '0');
        Node* left = build(exp, l, r - 2, match);
        return new Node(exp[r - 1],
                        exp[r - 1] == '|' ? (left->val | right->val) : (left->val & right->val),
                        left, right);
    }
};


int main() {

    cout << Solution().minOperationsToFlip("1&(0|1)") << endl;
    // 1

    cout << Solution().minOperationsToFlip("(0&0)&(0&0&0)") << endl;
    // 3

    cout << Solution().minOperationsToFlip("(0|(1|0&1))") << endl;
    // 1

    cout << Solution().minOperationsToFlip("1|1|(0&0)&1") << endl;
    // 1

    cout << Solution().minOperationsToFlip("1&0|(0&0)&0|0&(1&(1))") << endl;
    // 1

    return 0;
}
