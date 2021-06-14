/// Source : https://leetcode.com/problems/palindrome-pairs/
/// Author : liuyubobobo
/// Time   : 2021-06-14

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;


/// Using HashMap
/// Time Complexity: O(n*k^2)
/// Space Complexity: O(nk)
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {

        unordered_map<string, int> table;
        for(int i = 0; i < words.size(); i ++)
            table[words[i]] = i;

        set<vector<int>> res;
        for(int i = 0; i < words.size(); i ++){

            string a = "";
            unordered_map<string, int>::iterator iter;
            for(int j = 0; j < words[i].size(); j ++){
                a = string(1, words[i][j]) + a;
                iter = table.find(a);
                if(iter != table.end() && i != iter->second && is_palindrome(words[i], j + 1, words[i].size() - 1))
                    res.insert({i, iter->second});
            }

            a = "";
            for(int j = words[i].size() - 1; j >= 0; j --){
                a += words[i][j];
                iter = table.find(a);
                if(iter != table.end() && i != iter->second && is_palindrome(words[i], 0, j - 1))
                    res.insert({iter->second, i});
            }

            iter = table.find("");
            if(iter != table.end() && i != iter->second && is_palindrome(words[i], 0, words[i].size() - 1))
                res.insert({i, iter->second}), res.insert({iter->second, i});
        }
        return vector<vector<int>>(res.begin(), res.end());
    }

private:
    bool is_palindrome(const string& s, int start, int end){

        if(start >= end) return true;

        for(int i = start, j = end; i < j; i ++, j --)
            if(s[i] != s[j]) return false;
        return true;
    }
};


void print_res(const vector<vector<int>>& v){
    for(const vector<int>& e: v) cout << e[0] << " " << e[1] << endl;
}

int main() {

    vector<string> words1 = {"a","ab"};
    print_res(Solution().palindromePairs(words1));

    return 0;
}
