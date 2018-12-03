/// Source : https://leetcode.com/problems/count-of-smaller-numbers-after-self/
/// Author : liuyubobobo
/// Time   : 2018-12-03

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Using BST
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class BST{

private:
    class TreeNode{
    public:
        int val, sz;
        TreeNode *left, *right;
        TreeNode(int val): val(val), sz(1), left(NULL), right(NULL){}
    };
    TreeNode* root;

public:
    BST(): root(NULL){}

    void add(int x){
        root = add(root, x);
    }

    int smaller_than(int x){
        return smaller_than(root, x);
    }

private:
    TreeNode* add(TreeNode* node, int x){
        if(!node)
            return new TreeNode(x);

        if(x <= node->val)
            node->left = add(node->left, x);
        else
            node->right = add(node->right, x);
        node->sz ++;
        return node;
    }

    int smaller_than(TreeNode* node, int x){

        if(!node)
            return 0;

        if(x <= node->val)
            return smaller_than(node->left, x);
        return (node->left ? node->left->sz : 0) + 1 + smaller_than(node->right, x);
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {

        vector<int> res;
        if(nums.size() == 0)
            return res;

        res.push_back(0);
        if(nums.size() == 1)
            return res;

        BST bst;
        bst.add(nums.back());
        for(int i = nums.size() - 2; i >= 0; i --){
            bst.add(nums[i]);
            res.push_back(bst.smaller_than(nums[i]));
        }
        reverse(res.begin(), res.end());
        return res;
    }
};


void print_vec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    vector<int> nums1 = {5, 2, 6, 1};
    print_vec(Solution().countSmaller(nums1));
    // 2 1 1 0

    vector<int> nums2 = {2, 0, 1};
    print_vec(Solution().countSmaller(nums2));
    // 2 0 0

    return 0;
}