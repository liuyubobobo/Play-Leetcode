/// Source : https://leetcode.com/problems/design-an-expression-tree-with-evaluate-function/
/// Author : liuyubobobo
/// Time   : 2020-11-01

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


/// Stack
/// Tiime Complexity: O(n)
/// Space Complexity: O(n)

/**
 * This is the interface for the expression tree Node.
 * You should not remove it, and you can define some classes to implement it.
 */
class Node {
public:
    virtual ~Node () {};
    virtual int evaluate() const = 0;
protected:
    // define your fields here

};

class MyNode: public Node{

public:
    char op;
    int num;
    MyNode* left, *right;

    MyNode(string s): left(nullptr), right(nullptr){
        if(isdigit(s[0])) op = ' ', num = atoi(s.c_str());
        else op = s[0];
    }

    int evaluate() const{
        return dfs(this);
    }

private:
    int dfs(const MyNode* node) const{

        if(node->op == ' ') return node->num;

        int a = dfs(node->left), b = dfs(node->right);
        if(node->op == '+') return a + b;
        if(node->op == '-') return a - b;
        if(node->op == '*') return a * b;
        return a / b;
    }
};


/**
 * This is the TreeBuilder class.
 * You can treat it as the driver code that takes the postinfix input
 * and returns the expression tree represnting it as a Node.
 */
class TreeBuilder {
public:
    Node* buildTree(vector<string>& postfix) {

        stack<MyNode*> stack;
        for(const string& s: postfix){
            MyNode* node = new MyNode(s);
            if(node->op == ' ') stack.push(node);
            else{
                MyNode* b = stack.top(); stack.pop();
                MyNode* a = stack.top(); stack.pop();
                node->left = a, node->right = b;
                stack.push(node);
            }
        }
        return stack.top();
    }
};


int main() {

    vector<string> s1 = {"3","4","+","2","*","7","/"};
    Node* root1 =TreeBuilder().buildTree(s1);
    cout << root1->evaluate() << endl;
    // 2

    vector<string> s2 = {"4","5","7","2","+","-","*"};
    Node* root2 =TreeBuilder().buildTree(s2);
    cout << root2->evaluate() << endl;
    // -16

    vector<string> s3 = {"4","2","+","3","5","1","-","*","+"};
    Node* root3 =TreeBuilder().buildTree(s3);
    cout << root3->evaluate() << endl;
    // 18

    vector<string> s4 = {"100","200","+","2","/","5","*","7","+"};
    Node* root4 =TreeBuilder().buildTree(s4);
    cout << root4->evaluate() << endl;
    // 757

    return 0;
}
