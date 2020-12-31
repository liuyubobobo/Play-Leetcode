/// Source : https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/description/
/// Author : liuyubobobo
/// Time   : 2018-10-16

#include <iostream>
#include <queue>

using namespace std;


/// Using BFS
/// Time Complexity: O(n)
/// Space Complexity: O(n)

/// Definition for binary tree with next pointer.
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {

        if(!root)
            return;

        queue<TreeLinkNode*> q;
        q.push(root);
        int level_num = 1;
        while(!q.empty()){

            int new_level_num = 0;
            for(int i = 0; i < level_num; i ++){
                TreeLinkNode* node = q.front();
                q.pop();
                node->next = (i == level_num - 1 ? NULL : q.front());

                if(node->left){
                    q.push(node->left);
                    new_level_num ++;
                }

                if(node->right){
                    q.push(node->right);
                    new_level_num ++;
                }
            }

            level_num = new_level_num;
        }
    }
};

int main() {

    return 0;
}