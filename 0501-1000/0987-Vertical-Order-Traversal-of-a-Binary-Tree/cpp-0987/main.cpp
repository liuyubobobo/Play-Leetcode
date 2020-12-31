/// Source : https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
/// Author : liuyubobobo
/// Time   : 2019-02-02

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// DFS
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        map<int, vector<pair<int, int>>> pos;
        dfs(root, 0, 0, pos);

        vector<vector<int>> res;
        for(pair<int, vector<pair<int, int>>> p: pos){
            sort(p.second.begin(), p.second.end());
            vector<int> r;
            for(const pair<int, int>& e: p.second)
                r.push_back(e.second);
            res.push_back(r);
        }
        return res;
    }

private:
    void dfs(TreeNode* node, int x, int y, map<int, vector<pair<int, int>>>& pos){

        if(!node)
            return;

        pos[x].push_back(make_pair(y, node->val));
        dfs(node->left, x - 1, y + 1, pos);
        dfs(node->right, x + 1, y + 1, pos);
    }
};


int main() {

    // [0,5,1,9,null,2,null,null,null,null,3,4,8,6,null,null,null,7]
    // [[9,7],[5,6],[0,2,4],[1,3],[8]]

    return 0;
}