/// Source : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description/
/// Author : liuyubobobo
/// Time   : 2018-08-18

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/// Recursion
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {

        int n = pre.size();
        return construct(pre, 0, n - 1, post, 0, n - 1);
    }

private:
    TreeNode* construct(const vector<int>& pre, int preL, int preR,
                        const vector<int>& post, int postL, int postR){

        if(preL > preR)
            return NULL;

        assert(preR - preL + 1 == postR - postL + 1);

        if(preL == preR){
            assert(postL == postR && pre[preL] == post[postL]);
            return new TreeNode(pre[preL]);
        }

        assert(pre[preL] == post[postR]);
        TreeNode* root = new TreeNode(pre[preL]);

        int postPos = find(post.begin(), post.end(), pre[preL + 1]) - post.begin();
        assert(postPos >= postL && postPos <= postR - 1);

        int prePos = find(pre.begin(), pre.end(), post[postR - 1]) - pre.begin();
        assert(prePos >= preL + 1 && prePos <= preR);

        if(pre[prePos] == post[postPos])
            root->left = construct(pre, preL + 1, preR, post, postL, postR - 1);
        else {
            root->left = construct(pre, preL + 1, prePos - 1, post, postL, postPos);
            root->right = construct(pre, prePos, preR, post, postPos + 1, postR - 1);
        }

        return root;
    }
};


int main() {

    vector<int> pre1 = {1, 2, 4, 5, 3, 6, 7};
    vector<int> post1 = {4, 5, 2, 6, 7, 3, 1};
    Solution().constructFromPrePost(pre1, post1);

    vector<int> pre2 = {2, 1};
    vector<int> post2 = {1, 2};
    Solution().constructFromPrePost(pre2, post2);

    vector<int> pre3 = {2, 1, 3};
    vector<int> post3 = {3, 1, 2};
    Solution().constructFromPrePost(pre3, post3);

    return 0;
}