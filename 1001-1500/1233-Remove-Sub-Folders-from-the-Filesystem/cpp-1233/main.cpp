/// Source : https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/
/// Author : liuyubobobo
/// Time   : 2019-10-19

#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;


/// Trie
/// Time Complexity: O(total splits)
/// Space Complexity: O(total splits)
class Solution {

private:
    class Node{

    public:
        string s;
        map<string, Node*> next;

        Node(): s(""){}
    };

    Node* trie = NULL;

public:
    vector<string> removeSubfolders(vector<string>& folder) {

        trie = new Node();
        for(const string& s: folder){
            vector<string> vec = split(s);
//            for(const string e: vec) cout << e << " "; cout << endl;

            Node* cur = trie;
            for(const string& f: vec) {
                if (!cur->next.count(f)) cur->next[f] = new Node();
                cur = cur->next[f];
            }
            cur->s = s;
        }

        set<string> set(folder.begin(), folder.end());
        dfs(trie, false, set);
        return vector<string>(set.begin(), set.end());
    }

private:
    void dfs(Node* node, bool parent, set<string>& set){

        if(node->s != "" && parent) set.erase(node->s);

        for(const pair<string, Node*>& p: node->next)
            dfs(p.second, parent || node->s != "", set);
    }

    vector<string> split(const string& s){
        vector<string> res;
        for(int start = 1, i = start + 1; i <= s.size(); i ++)
            if(i == s.size() || s[i] == '/'){
                res.push_back(s.substr(start, i - start));
                start = i + 1;
                i = start;
            }
        return res;
    }
};


void print_vec(const vector<string>& v){
    for(const string& s: v) cout << s << " "; cout << endl;
}

int main() {

    vector<string> folders1 = {"/a","/a/b","/c/d","/c/d/e","/c/f"};
    print_vec(Solution().removeSubfolders(folders1));
    // "/a","/c/d","/c/f"

    vector<string> folders2 = {"/a","/a/b/c","/a/b/d"};
    print_vec(Solution().removeSubfolders(folders2));
    // "/a"

    vector<string> folders3 = {"/a/b/c","/a/b/ca","/a/b/d"};
    print_vec(Solution().removeSubfolders(folders3));
    // "/a/b/c" "/a/b/ca" "/a/b/d"

    return 0;
}