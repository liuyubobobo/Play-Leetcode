/// Source : https://leetcode.com/problems/delete-duplicate-folders-in-system/
/// Author : liuyubobobo
/// Time   : 2021-07-24

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>

using namespace std;


/// Tree Encoding
/// No need to delete in string
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

private:
    class Node{

    public:
        string desc, sub_folder;
        map<string, Node*> next;

        Node(const string& desc) : desc(desc), sub_folder(""){};
    };

    Node* root;

public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {

        root = new Node("/");
        for(const vector<string>& path: paths)
            add(root, path);

        map<string, int> sub_structure;
        string tree_s = dfs(root, sub_structure);

        vector<vector<string>> res;
        for(const pair<string, Node*>& p: root->next){
            vector<string> path;
            dfs_res(p.second, path, res, sub_structure);
        }
        return res;
    }

private:
    void dfs_res(Node* node, vector<string>& path, vector<vector<string>>& res,
                 map<string, int>& sub_structure){

        if(sub_structure[node->sub_folder] >= 2) return;

        path.push_back(node->desc);
        res.push_back(path);

        for(const pair<string, Node*>& p: node->next)
            dfs_res(p.second, path, res, sub_structure);
        path.pop_back();
    }

    string dfs(Node* node, map<string, int>& sub_structure){

        if(node->next.size() == 0){
            return node->desc;
        }

        string ret = "";
        for(const pair<string, Node*>& p: node->next){
            string s = p.first;
            Node* nextnode = p.second;
            ret += "(" + dfs(nextnode, sub_structure) + ")";
        }

//        cout << "folder structure : " << node->desc << " : ";
//        cout << ret << endl;

        string the_folder_s = node->desc + ret;

        sub_structure[ret] ++;

        node->sub_folder = ret;

        return the_folder_s;
    }

    void add(Node* root, const vector<string>& path){

        Node* cur = root;
        for(const string& s: path){
            if(!cur->next.count(s))
                cur->next[s] = new Node(s);
            cur = cur->next[s];
        }
    }
};


void print_res(const vector<vector<string>>& v){
    if(v.empty()) cout << "empty" << endl;
    for(const vector<string>& e: v){
        for(const string& s: e) cout << s << ' '; cout << endl;
    }
}

int main() {

//    vector<vector<string>> paths1 = {{"a"},{"c"},{"d"}, {"a","b"},{"c","b"},{"d","a"}};
//    print_res(Solution().deleteDuplicateFolder(paths1));
//
//    cout << endl;
//
//    vector<vector<string>> paths2 = {{"a"},{"c"},{"a","b"},{"c","b"},{"a","b","x"},{"a","b","x","y"},{"w"},{"w","y"}};
//    print_res(Solution().deleteDuplicateFolder(paths2));
//
//    cout << endl;
//
//    vector<vector<string>> paths3 = {{"a","b"},{"c","d"},{"c"},{"a"}};
//    print_res(Solution().deleteDuplicateFolder(paths3));
//
//    cout << endl;
//
//    vector<vector<string>> paths4 = {{"a"}, {"a","x"},{"a","x", "y"},{"a", "z"},{"b"}, {"b", "x"}, {"b","x", "y"}, {"b", "z"}};
//    print_res(Solution().deleteDuplicateFolder(paths4));
//
//    cout << endl;

    vector<vector<string>> paths5 = {{"a"}, {"a","x"},{"a","x", "y"},{"a", "z"},{"b"}, {"b", "x"}, {"b","x", "y"}, {"b", "z"}, {"b", "w"}};
    print_res(Solution().deleteDuplicateFolder(paths5));

    cout << endl;
    return 0;
}
