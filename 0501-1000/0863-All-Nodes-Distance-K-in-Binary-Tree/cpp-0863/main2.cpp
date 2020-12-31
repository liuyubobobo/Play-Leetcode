/// Source : https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/
/// Author : liuyubobobo
/// Time   : 2018-07-01

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <queue>

using namespace std;

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/// Construct a Graph and Using BFS
/// An mch easier way to construct the Graph :)
///
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {

        if(K == 0)
            return {target->val};

        unordered_map<TreeNode*, TreeNode*> parents;
        dfs(root, NULL, parents);

        vector<int> res;
        unordered_set<TreeNode*> visited;

        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(target, 0));
        visited.insert(target);
        while(!q.empty()){
            TreeNode* curNode = q.front().first;
            int curDis = q.front().second;
            q.pop();
            if(curDis == K)
                res.push_back(curNode->val);

            unordered_map<TreeNode*, TreeNode*>::iterator piter = parents.find(curNode);
            if(piter != parents.end() && visited.find(piter->second) == visited.end()){
                q.push(make_pair(piter->second, curDis + 1));
                visited.insert(piter->second);
            }

            if(curNode->left != NULL && visited.find(curNode->left) == visited.end()){
                q.push(make_pair(curNode->left, curDis + 1));
                visited.insert(curNode->left);
            }

            if(curNode->right != NULL && visited.find(curNode->right) == visited.end()){
                q.push(make_pair(curNode->right, curDis + 1));
                visited.insert(curNode->right);
            }
        }
        return res;
    }

private:
    void dfs(TreeNode* root, TreeNode* parent,
             unordered_map<TreeNode*, TreeNode*>& parents){

        if(root == NULL)
            return;

        if(parent != NULL)
            parents[root] = parent;

        dfs(root->left, root, parents);
        dfs(root->right, root, parents);
    }
};


int main() {

    return 0;
}