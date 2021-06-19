/// Source : https://leetcode-cn.com/problems/er-cha-shu-ren-wu-diao-du/
/// Author : liuyubobobo
/// Time   : 2020-04-20

#include <iostream>

using namespace std;


/// DFS
/// Time Complexity: O(n)
/// Space Complexity: O(h)

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    double minimalExecTime(TreeNode* root) {

        pair<int, int> res = dfs(root);
        return res.first + res.second / 2.0;
    }

private:
    pair<int, int> dfs(TreeNode* node){

        if(!node) return {0, 0};

        pair<int, int> t1 = dfs(node->left);
        pair<int, int> t2 = dfs(node->right);
//        cout << node->val << endl;
//        cout << "t1 : s = " << t1.first << " p = " << t1.second << endl;
//        cout << "t2 : s = " << t2.first << " p = " << t2.second << endl;

        int s = node->val, p = 0;

        if(t1.first < t2.first) swap(t1, t2);
        int newp = min(t1.first, t2.first);
        p += 2 * newp;
        t1.first -= newp, t2.first -= newp;

        if(t1.first && t2.second){
            newp = min(t1.first, t2.second);
            p += 2 * newp;
            t1.first -= newp, t2.second -= newp;
        }

        s += t1.first;
        p += t1.second + t2.second;

        return {s, p};
    }
};


int main() {

    return 0;
}
