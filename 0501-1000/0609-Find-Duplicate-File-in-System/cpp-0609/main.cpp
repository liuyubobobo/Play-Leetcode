/// Source : https://leetcode.com/problems/find-duplicate-file-in-system/
/// Author : liuyubobobo
/// Time   : 2021-05-18

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;


/// Using HashMap
/// Time Complexity: O(|all files|)
/// Space Complexity: O(|all files|)
class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {

        unordered_map<string, vector<string>> table;
        for(const string& path: paths){
            vector<string> v = split(path);

            for(int i = 1; i < v.size(); i ++){
                vector<string> file = parse(v[i]);
                table[file[1]].push_back(v[0] + "/" + file[0]);
            }
        }

        vector<vector<string>> res;
        for(const pair<string, vector<string>>& p: table)
            if(p.second.size() > 1)
                res.push_back(p.second);
        return res;
    }

private:
    vector<string> parse(const string& s){

        int l = s.find('(');
        assert(l != string::npos);

        int r = s.find(')', l + 1);
        assert(r != string::npos);

        return {s.substr(0, l), s.substr(l + 1, r - l - 1)};
    }

    vector<string> split(const string& s){

        vector<string> res;
        for(int start = 0, i = 1; i <= s.size(); i ++)
            if(i == s.size() || s[i] == ' '){
                res.push_back(s.substr(start, i - start));

                start = i + 1;
                i = start;
            }
        return res;
    }
};


void print(const vector<vector<string>>& res){

    for(const vector<string>& v: res){
        for(const string& s: v) cout << s << " "; cout << endl;
    }
}

int main() {

    vector<string> paths1 = {"root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)","root 4.txt(efgh)"};
    print(Solution().findDuplicate(paths1));

    return 0;
}
