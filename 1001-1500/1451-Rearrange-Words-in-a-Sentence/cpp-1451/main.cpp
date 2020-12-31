/// Source : https://leetcode.com/problems/rearrange-words-in-a-sentence/
/// Author : liuyubobobo
/// Time   : 2020-05-16

#include <iostream>
#include <vector>

using namespace std;


/// Split + Sort
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    string arrangeWords(string text) {

        text[0] = tolower(text[0]);
        vector<pair<string, int>> words;
        int cnt = 0;
        for(int start = 0, i = 0; i <= text.size(); i ++)
            if(i == text.size() || text[i] == ' '){
                words.push_back({text.substr(start, i - start), cnt ++});
                start = i + 1;
                i = start;
            }

        sort(words.begin(), words.end(),
             [](const pair<string, int>& p1, const pair<string, int>& p2){
           if(p1.first.size() != p2.first.size()) return p1.first.size() < p2.first.size();
           return p1.second < p2.second;
        });

        string res = words[0].first;
        for(int i = 1; i < words.size(); i ++)
            res += " " + words[i].first;
        res[0] = toupper(res[0]);
        return res;
    }
};


int main() {

    cout << Solution().arrangeWords("Leetcode is cool") << endl;

    cout << Solution().arrangeWords("Keep calm and code on") << endl;

    cout << Solution().arrangeWords("To be or not to be") << endl;

    return 0;
}
