/// Source : https://leetcode.com/problems/even-odd-tree/
/// Author : liuyubobobo
/// Time   : 2020-10-03

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(n)

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {

        vector<vector<int>> data;
        dfs(root, 0, data);

        for(int l = 0; l < data.size(); l += 2)
            if(!okEven(data[l])) return false;

        for(int l = 1; l < data.size(); l += 2)
            if(!okOdd(data[l])) return false;

        return true;
    }

private:
    bool okOdd(const vector<int>& v){

        for(int e: v) if(e % 2 == 1) return false;

        for(int i = 1; i < v.size(); i ++)
            if(v[i] >= v[i - 1]) return false;

        return true;
    }

    bool okEven(const vector<int>& v){

        for(int e: v) if(e % 2 == 0) return false;

        for(int i = 1; i < v.size(); i ++)
            if(v[i] <= v[i - 1]) return false;

        return true;
    }

    void dfs(TreeNode* node, int level, vector<vector<int>>& data){

        if(level >= data.size()) data.push_back(vector<int>());

        data[level].push_back(node->val);

        if(node->left) dfs(node->left, level + 1, data);
        if(node->right) dfs(node->right, level + 1, data);
    }
};


int main() {

    return 0;
}
