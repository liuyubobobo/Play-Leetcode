/// Source : https://leetcode.com/problems/binary-search-tree-iterator/description/
/// Author : liuyubobobo
/// Time   : 2018-06-06

#include <iostream>
#include <stack>
#include <vector>
#include <cassert>

using namespace std;

/// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/// Using My Non-recursive Inorder Traversal Algorithm
///
/// Time Complexity: initial: O(1)
///                  hasNext: O(h)
///                  next: O(h)
/// Space Complexity: O(h)
class BSTIterator {

private:
    struct Command{
        string s;   // go, visit
        TreeNode* node;
        Command(string s, TreeNode* node): s(s), node(node){}
    };

    stack<Command> myStack;

public:
    BSTIterator(TreeNode *root) {

        if(root != NULL)
            myStack.push(Command("go", root));
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {

        while(!myStack.empty()){
            Command command = myStack.top();
            myStack.pop();

            if(command.s == "visit"){
                myStack.push(command);
                return true;
            }
            else{
                assert(command.s == "go");
                if(command.node->right)
                    myStack.push(Command("go",command.node->right));
                myStack.push(Command("visit", command.node));
                if(command.node->left)
                    myStack.push(Command("go",command.node->left));
            }
        }

        return false;
    }

    /** @return the next smallest number */
    int next() {

        while(!myStack.empty()){
            Command command = myStack.top();
            myStack.pop();

            if(command.s == "visit")
                return command.node->val;
            else{
                assert(command.s == "go");
                if(command.node->right)
                    myStack.push(Command("go",command.node->right));
                myStack.push(Command("visit", command.node));
                if(command.node->left)
                    myStack.push(Command("go",command.node->left));
            }
        }

        assert(false);
        return -1;
    }
};


int main() {

    return 0;
}