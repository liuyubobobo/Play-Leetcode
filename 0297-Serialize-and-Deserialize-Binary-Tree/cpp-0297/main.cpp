/// Source : https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
/// Author : liuyubobobo
/// Time   : 2018-09-17

#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

using namespace std;


/// BFS
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

        queue<TreeNode*> q;
        q.push(root);
        ret += to_string(root->val);
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();

            if(cur->left){
                ret += "," + to_string(cur->left->val);
                q.push(cur->left);
            }
            else
                ret += ",null";

            if(cur->right){
                ret += "," + to_string(cur->right->val);
                q.push(cur->right);
            }
            else
                ret += ",null";
        }
        return ret + "]";
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> vec = get_vector(data);

        if(vec.size() == 0 || (vec.size() == 1 && vec[0] == "null"))
            return NULL;

        TreeNode* root = new TreeNode(atoi(vec[0].c_str()));
        queue<TreeNode*> q;
        q.push(root);
        int index = 1;
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();

            assert(vec.size() - index >= 2);
            if(vec[index] != "null"){
                cur->left = new TreeNode(atoi(vec[index].c_str()));
                q.push(cur->left);
            }
            index ++;

            if(vec[index] != "null"){
                cur->right = new TreeNode(atoi(vec[index].c_str()));
                q.push(cur->right);
            }
            index ++;
        }
        return root;
    }

private:
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