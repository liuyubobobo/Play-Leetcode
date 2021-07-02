/// Source : https://leetcode-cn.com/problems/xu-lie-hua-er-cha-shu-lcof/
/// Author : liuyubobobo
/// Time   : 2021-06-30

#include <iostream>
#include <vector>

using namespace std;


/// DFS
/// Time Complexity: O(n)
/// Space Complexity: O(n)
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

    return 0;
}
