/// Source : https://leetcode.com/problems/binary-tree-paths/description/
/// Author : liuyubobobo
/// Time   : 2020-10-20

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;


/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x, TreeNode* lt, TreeNode* rt) : val(x), left(lt), right(rt) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/// Non-Recursive
/// Using Command Stack to simulate system stack
///
/// Time Complexity: O(n), where n is the node's number in the tree
/// Space Complexity: O(h), where h is the height of the tree
class Solution {

private:
    struct Command{
        string s;   // go, print, pop
        TreeNode* node;
        Command(string s, TreeNode* node): s(s), node(node){}
    };

public:
    vector<string> binaryTreePaths(TreeNode* root) {

        if(root == nullptr) return {};

        vector<string> res;
        if(root == NULL)
            return res;

        stack<Command> command_stack;
        vector<TreeNode*> path;

        command_stack.push(Command("go", root));

        while(!command_stack.empty()){
            Command command = command_stack.top();
            command_stack.pop();

            if(command.s == "do"){
                path.push_back(command.node);
                if(command.node->left == nullptr && command.node->right == nullptr){
                    string str = to_string(path[0]->val);
                    for(int i = 1; i < path.size(); i ++)
                        str += "->" + to_string(path[i]->val);
                    res.push_back(str);
                }
            }
            else if(command.s == "pop"){
                path.pop_back();
            }
            else{
                command_stack.push(Command("pop", command.node));

                if(command.node->right)
                    command_stack.push(Command("go",command.node->right));
                if(command.node->left)
                    command_stack.push(Command("go",command.node->left));

                command_stack.push(Command("do", command.node));

            }
        }
        return res;
    }
};


void print_vec(const vector<string>& v){
    for(const string& s: v) cout << s << '\n';
}

int main() {

    TreeNode* root1 = new TreeNode(1, new TreeNode(2, NULL, new TreeNode(5)), new TreeNode(3));
    print_vec(Solution().binaryTreePaths(root1));

    return 0;
}