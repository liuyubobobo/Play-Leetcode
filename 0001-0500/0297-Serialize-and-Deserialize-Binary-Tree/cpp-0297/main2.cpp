/// Source : https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
/// Author : liuyubobobo
/// Time   : 2018-09-17

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/// DFS
/// Time Complexity: O(n)
/// Space Complexity: O(n)

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        if(!root)
            return "[null]";

        string ret = "[";
        dfs(root, ret);
        ret.pop_back();
        return ret + "]";
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> vec = get_vector(data);

        if(vec.size() == 0 || (vec.size() == 1 && vec[0] == "null"))
            return NULL;

//        for(const string& s: vec)
//            cout << s << " ";
//        cout << endl;

        int index = 0;
        return dfs(vec, index);
    }

private:
    TreeNode* dfs(const vector<string>& vec, int& index){

        if(index == vec.size() || vec[index] == "null")
            return NULL;

        TreeNode* node = new TreeNode(atoi(vec[index].c_str()));
        index ++;
        node->left = dfs(vec, index);

        index ++;
        node->right = dfs(vec, index);

        return node;
    }

    void dfs(TreeNode* node, string& ret){

        ret += to_string(node->val) + ",";

        if(node->left)
            dfs(node->left, ret);
        else
            ret += "null,";

        if(node->right)
            dfs(node->right, ret);
        else
            ret += "null,";
    }

    vector<string> get_vector(const string& data){

        string s = data.substr(1, data.size() - 2) + ",";

        vector<string> res;
        int i = 0;
        while(i < s.size()){
            int comma = s.find(',', i);
            res.push_back(s.substr(i, comma - i));
            i = comma + 1;
        }
        return res;
    }
};


int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    string s = Codec().serialize(root);
    cout << s << endl;

    TreeNode* x = Codec().deserialize(s);
    cout << Codec().serialize(x) << endl;

    return 0;
}