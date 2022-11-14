/// Source : https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/
/// Author : liuyubobobo
/// Time   : 2022-11-13

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// BFS + Greedy
/// Time Complexity: O(nlogn)
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
    int minimumOperations(TreeNode* root) {

        queue<TreeNode*> q;
        q.push(root);
        int res = 0;
        vector<int> num2index(1e5 + 1, -1);
        while(!q.empty()){

            vector<TreeNode*> v;
            while(!q.empty()) v.push_back(q.front()), q.pop();

            vector<int> data(v.size());
            for(int i = 0; i < v.size(); i ++) data[i] = v[i]->val;

            res += solve(data.size(), data, num2index);

            for(TreeNode* node: v){
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return res;
    }

private:
    int solve(int n, vector<int>& data, vector<int>& num2index){

        for(int i = 0; i < n; i ++) num2index[data[i]] = i;

        vector<int> sorted_data = data;
        sort(sorted_data.begin(), sorted_data.end());

        int res = 0;
        for(int i = 0; i < n; i ++){
            int j = num2index[sorted_data[i]];
            if(i != j){
                res ++;
                swap(data[i], data[j]);
                num2index[data[j]] = j;
            }
        }
        return res;
    }
};


int main() {

    TreeNode* left = new TreeNode(4, new TreeNode(7), new TreeNode(6));
    TreeNode* right = new TreeNode(3, new TreeNode(8, new TreeNode(9), nullptr), new TreeNode(5, new TreeNode(10),
                                                                                              nullptr));
    TreeNode* root = new TreeNode(1, left, right);
    cout << Solution().minimumOperations(root) << '\n';
    // 3

    return 0;
}
