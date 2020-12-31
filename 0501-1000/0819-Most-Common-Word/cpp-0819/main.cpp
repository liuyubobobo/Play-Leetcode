/// Source : https://leetcode.com/problems/most-common-word/description/
/// Author : liuyubobobo
/// Time   : 2018-04-14

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

/// Counting
///
/// Time Complexity: O(len(paragraph) + len(banned))
/// Space Complexity: O(len(banned))
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {

        transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower);
        unordered_set<string> banned_set;
        for(const string& word: banned)
            banned_set.insert(word);

        unordered_map<string, int> freq;
        int start = firstLetter(paragraph, 0);
        for(int i = start + 1 ; i <= paragraph.size() ;){
            if(i == paragraph.size() || !islower(paragraph[i])){
                string word = paragraph.substr(start, i - start);
                if(banned_set.find(word) == banned_set.end())
                    freq[word] += 1;
                start = firstLetter(paragraph, i + 1);
                i = start + 1;
            }
            else
                i ++;
        }

        int max_freq = 0;
        string res = "";
        for(const pair<string, int>& p: freq)
            if(p.second > max_freq){
                res = p.first;
                max_freq = p.second;
            }
        return res;
    }

private:
    int firstLetter(const string& s, int start){

        for(int i = start ; i < s.size() ; i ++)
            if(islower(s[i]))
                return i;
        return s.size();
    }
};

int main() {

    string paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.";
    vector<string> banned = {"hit"};
    cout << Solution().mostCommonWord(paragraph, banned) << endl;

    return 0;
}