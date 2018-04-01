/// Source : https://leetcode.com/problems/expressive-words/description/
/// Author : liuyubobobo
/// Time   : 2018-03-31

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/// Ad-Hoc
/// Time Complexity: O(len(words) * len(words[i]))
/// Space Complexity: O(max_length_of_words)
class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {

        vector<string> S_groups = get_groups(S);

        int res = 0;
        for(const string& word: words)
            if(ok(word, S_groups)){
                // cout << "ok!" << word << endl;
                res ++;
            }
        return res;
    }

private:
    bool ok(const string& s, const vector<string>& S_groups){

        vector<string> s_groups = get_groups(s);
        if(s_groups.size() != S_groups.size())
            return false;

        for(int i = 0 ; i < s_groups.size() ; i ++){
            if(s_groups[i][0] != S_groups[i][0])
                return false;
            if(s_groups[i].size() > S_groups[i].size())
                return false;
            if(s_groups[i].size() == S_groups[i].size())
                continue;

            assert(s_groups[i].size() < S_groups[i].size());
            if(S_groups[i].size() <= 2)
                return false;
        }
        return true;
    }

    vector<string> get_groups(const string& s){
        vector<string> res;
        int start = 0;
        for(int i = start + 1 ; i <= s.size() ; )
            if(i == s.size() || s[i] != s[start]){
                res.push_back(s.substr(start, i - start));
                start = i;
                i = start + 1;
            }
            else
                i ++;
        return res;
    }
};

int main() {

    string S1 = "heeellooo";
    vector<string> words1 = {"hello", "hi", "helo"};
    cout << Solution().expressiveWords(S1, words1) << endl;

    return 0;
}