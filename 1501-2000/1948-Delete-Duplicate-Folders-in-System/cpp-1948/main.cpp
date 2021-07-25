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
/// Delete in String and construct the new tree based on string
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

private:
    class Node{

    public:
        string desc;
        map<string, Node*> next;

        Node(const string& desc) : desc(desc){};
    };

    Node* root;

public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {

        root = new Node("/");
        for(const vector<string>& path: paths)
            add(root, path);

        map<string, multiset<string>> sub_structure;
        string tree_s = dfs(root, sub_structure);

        vector<string> del_vec;
        for(const pair<string, multiset<string>>& p: sub_structure)
            if(p.second.size() > 1){
                for(const string& del: p.second) del_vec.push_back(del);
            }

        sort(del_vec.begin(), del_vec.end(), [](const string& a, const string& b){
           if(a.size() != b.size()) return a.size() > b.size();
           return a < b;
        });

        for(const string& del: del_vec) del_folder(tree_s, del);
        del_folder(tree_s, "()");

//        cout << tree_s << endl;
        vector<int> right(tree_s.size(), -1);
        stack<int> stack;
        for(int i = 0; i < tree_s.size(); i ++)
            if(tree_s[i] == '(') stack.push(i);
            else if(tree_s[i] == ')') right[stack.top()] = i, stack.pop();
//        for(int e: right) cout << e << ' '; cout << endl;

        Node* new_root = build_tree(tree_s, 0, tree_s.size() - 1, right);

        vector<vector<string>> res;
        for(const pair<string, Node*>& p: new_root->next){
            vector<string> path;
            dfs_res(p.second, path, res);
        }
        return res;
    }

private:
    void dfs_res(Node* node, vector<string>& path, vector<vector<string>>& res){

        path.push_back(node->desc);
        res.push_back(path);

        for(const pair<string, Node*>& p: node->next)
            dfs_res(p.second, path, res);
        path.pop_back();
    }

    Node* build_tree(const string& s, int l, int r, const vector<int>& right){

        if(l > r) return nullptr;

        assert(s[l] != '(');

        int i = l;
        for(; i <= r; i ++)
            if(s[i] == '(') break;

        Node* ret = new Node(s.substr(l, i - l));

        while(i <= r){
            assert(s[i] == '(');
            int j = right[i];
            Node* node = build_tree(s, i + 1, j - 1, right);
            ret->next[node->desc] = node;

            i = j + 1;
        }
        return ret;
    }

    void del_folder(string& s, const string& t){

        while(true){
            int pos = s.find(t);
            if(pos == string::npos) return;
            s = s.substr(0, pos) + s.substr(pos + t.size());
        }
    }

    string dfs(Node* node, map<string, multiset<string>>& sub_structure){

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

        sub_structure[ret].insert(the_folder_s);

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
