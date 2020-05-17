/// Source : https://leetcode.com/problems/rearrange-words-in-a-sentence/
/// Author : liuyubobobo
/// Time   : 2020-05-16

#include <iostream>
#include <vector>

using namespace std;


/// Split + Stable Sort
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    string arrangeWords(string text) {

        text[0] = tolower(text[0]);
        vector<string> words;
        int cnt = 0;
        for(int start = 0, i = 0; i <= text.size(); i ++)
            if(i == text.size() || text[i] == ' '){
                words.push_back(text.substr(start, i - start));
                start = i + 1;
                i = start;
            }

        stable_sort(words.begin(), words.end(),
             [](const string& s1, const string& s2){ return s1.size() < s2.size(); });

        string res = words[0];
        for(int i = 1; i < words.size(); i ++)
            res += " " + words[i];
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
