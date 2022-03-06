/// Source : https://leetcode.com/problems/create-binary-tree-from-descriptions/
/// Author : liuyubobobo
/// Time   : 2022-03-05

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <cassert>

using namespace std;


/// Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(1)

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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {

        map<int, TreeNode*> value2node;
        set<int> is_child;
        for(const vector<int>& des: descriptions){
            int parent_value = des[0];
            TreeNode* parent_node = nullptr;
            if(value2node.count(parent_value))
                parent_node = value2node[parent_value];
            else{
                parent_node = new TreeNode(parent_value);
                value2node[parent_value] = parent_node;
            }

            int child_value = des[1];
            TreeNode* child_node = nullptr;
            if(value2node.count(child_value))
                child_node = value2node[child_value];
            else{
                child_node = new TreeNode(child_value);
                value2node[child_value] = child_node;
            }

            if(des[2]) parent_node->left = child_node;
            else parent_node->right = child_node;

            is_child.insert(child_value);
        }

        for(const vector<int>& des: descriptions)
            if(!is_child.count(des[0])) return value2node[des[0]];
        assert(false);
        return nullptr;
    }
};


int main() {

    return 0;
}
