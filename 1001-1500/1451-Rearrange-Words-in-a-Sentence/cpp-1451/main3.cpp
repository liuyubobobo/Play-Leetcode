/// Source : https://leetcode.com/problems/rearrange-words-in-a-sentence/
/// Author : liuyubobobo
/// Time   : 2020-05-16

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Split + Bucket Sort
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    string arrangeWords(string text) {

        text[0] = tolower(text[0]);

        map<int, vector<string>> buckets;
        int cnt = 0;
        for(int start = 0, i = 0; i <= text.size(); i ++)
            if(i == text.size() || text[i] == ' '){
                buckets[i - start].push_back(text.substr(start, i - start));
                start = i + 1;
                i = start;
            }

        string res = "";
        for(const pair<int, vector<string>>& p: buckets)
            for(const string& s: p.second)
                res += s + ' ';
        res[0] = toupper(res[0]);
        res.pop_back();
        return res;
    }
};


int main() {

    cout << Solution().arrangeWords("Leetcode is cool") << endl;

    cout << Solution().arrangeWords("Keep calm and code on") << endl;

    cout << Solution().arrangeWords("To be or not to be") << endl;

    return 0;
}
