/// Source : https://leetcode.com/problems/count-words-obtained-after-adding-a-letter/
/// Author : liuyubobobo
/// Time   : 2022-01-08

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Map
/// Time Complexity: O(|startWords| + |targetWords|)
/// Space Complexity: O(|targetWords|)
class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {

        unordered_map<string, int> target_map;
        for(string word: targetWords){
            sort(word.begin(), word.end());
            target_map[word] ++;
        }

        int res = 0;
        vector<bool> used(26);
        for(const string& word: startWords){
            used.assign(26, false);
            for(char c: word) used[c - 'a'] = true;
            for(int i = 0; i < 26; i ++)
                if(!used[i]){
                    string new_word = word + (char)('a' + i);
                    sort(new_word.begin(), new_word.end());
                    auto iter = target_map.find(new_word);
                    if(iter != target_map.end()){
                        res += iter->second;
                        target_map.erase(iter);
                    }
                }
        }
        return res;
    }
};


int main() {

    vector<string> startWords1 = {"ant","act","tack"};
    vector<string> targetWords1 = {"tack","act","acti"};
    cout << Solution().wordCount(startWords1, targetWords1) << endl;
    // 2

    vector<string> startWords2 = {"ab","a"};
    vector<string> targetWords2 = {"abc","abcd"};
    cout << Solution().wordCount(startWords2, targetWords2) << endl;
    // 1

    return 0;
}
