/// Source : https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/
/// Author : liuyubobobo
/// Time   : 2019-10-20

#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;


/// Sorting
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {

public:
    vector<string> removeSubfolders(vector<string>& folder) {

        sort(folder.begin(), folder.end());

        vector<string> res;
        for(int t = 0, i = 1; i <= folder.size(); i ++)
            if(i == folder.size() || !isSubfolder(folder[t], folder[i])){
                res.push_back(folder[t]);
                t = i;
                i = t;
            }
        return res;
    }

private:
    bool isSubfolder(const string& p, const string& s){
        if(p.size() > s.size()) return false;
        if(p.size() == s.size()) return p == s;
        return s.substr(0, p.size()) == p && s[p.size()] == '/';
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

    vector<string> folders4 = {"/a/b/c","/a/b/ca","/a/b/d"};
    print_vec(Solution().removeSubfolders(folders4));
    // "/a/b/c","/a/b/ca","/a/b/d"

    return 0;
}