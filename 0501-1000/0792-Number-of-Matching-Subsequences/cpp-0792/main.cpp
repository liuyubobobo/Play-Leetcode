/// Source : https://leetcode.com/problems/number-of-matching-subsequences/description/
/// Author : liuyubobobo
/// Time   : 2018-03-05

#include <iostream>
#include <vector>

using namespace std;


/// Next Letter Pointer
/// Time Complexity:
/// Space Complexity:
class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {

        vector<pair<string, int>> table[26];
        for(const string& word: words)
            table[word[0] - 'a'].push_back(make_pair(word, 0));

        int res = 0;
        for(char c: S){
            vector<pair<string, int>> old_table(table[c-'a'].begin(), table[c-'a'].end());
            table[c-'a'].clear();
            for(pair<string, int> p: old_table){
                p.second ++;
                if(p.second == p.first.size())
                    res ++;
                else
                    table[p.first[p.second] - 'a'].push_back(p);
            }
        }

        return res;
    }
};

int main() {

    vector<string> words = {"a", "bb", "acd", "ace"};
    string S = "abcde";
    cout << Solution().numMatchingSubseq(S, words) << endl;

    return 0;
}