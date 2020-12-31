#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<string>> partition(string s) {

        vector<vector<string>> res;
        vector<string> cur;
        dfs(s, 0, cur, res);
        return res;
    }

private:
    void dfs(const string& s, int l, vector<string>& cur,
             vector<vector<string>>& res){

        if(l == s.size()){
            res.push_back(cur);
            return;
        }

        for(int r = l; r < s.size(); r ++)
            if(ispalindrome(s, l, r)){
                cur.push_back(s.substr(l, r + 1 - l));
                dfs(s, r + 1, cur, res);
                cur.pop_back();
            }
    }

    bool ispalindrome(const string& s, int l, int r){

        while(l <= r){
            if(s[l] != s[r]) return false;
            l ++, r --;
        }
        return true;
    }
};


int main() {

    Solution().partition("efe");
    return 0;
}
