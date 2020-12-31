/// Source : https://leetcode.com/problems/flip-binary-tree-to-match-preorder-traversal/
/// Author : liuyubobobo
/// Time   : 2018-01-05

#include <iostream>
#include <vector>

using namespace std;


/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/// DFS
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {

        vector<int> res;
        int index = 0;
        if(!go(root, index, voyage, res))
            return {-1};
        return res;
    }

private:
    bool go(TreeNode* root, int& index, const vector<int>& voyage, vector<int>& res){

        if(!root){
            if(index < voyage.size())
                return false;
            return true;
        }

        if(index >= voyage.size() || root->val != voyage[index])
            return false;
        index ++;

        if(root->left && !root->right)
            return go(root->left, index, voyage, res);

        if(root->right && !root->left)
            return go(root->right, index, voyage, res);

        if(!root->left && !root->right)
            return true;

        if(root->left->val != voyage[index]){
            res.push_back(root->val);
            swap(root->left, root->right);
        }

        if(!go(root->left, index, voyage, res))
            return false;

        return go(root->right, index, voyage, res);
    }
};


void print_vec(const vector<int>& vec){

    if(vec.size() == 0)
        cout << "empty";
    else
        for(int e: vec)
            cout << e << " ";
    cout << endl;
}

int main() {

    // [1,null,2], [1,2]
    TreeNode* root1 = new TreeNode(1);
    root1->right = new TreeNode(2);
    vector<int> voyage1 = {1, 2};
    print_vec(Solution().flipMatchVoyage(root1, voyage1));

    return 0;
}