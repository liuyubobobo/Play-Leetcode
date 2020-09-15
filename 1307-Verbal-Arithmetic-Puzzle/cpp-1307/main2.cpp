/// Source : https://leetcode.com/problems/verbal-arithmetic-puzzle/
/// Author : liuyubobobo
/// Time   : 2020-09-14

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/// Backtracking
/// Make leading-zero check during searching
/// Time Complexity: O(10^10)
/// Space Complexity: O(|words| * max_len_of_words)
class Solution {

private:
    vector<int> pow10;
    unordered_set<char> leading_letters;

public:
    bool isSolvable(vector<string>& words, string result) {

        pow10 = {1};
        for(int i = 1; i <= 9; i ++)
            pow10.push_back(pow10[i - 1] * 10);

        leading_letters.clear();
        for(const string& word: words)
            leading_letters.insert(word[0]);
        leading_letters.insert(result[0]);

        int maxlen = 0;
        for(string& word: words) {
            reverse(word.begin(), word.end());
            maxlen = max(maxlen, (int)word.size());
        }
        reverse(result.begin(), result.end());
        maxlen = max(maxlen, (int)result.size());

        vector<int> letters(26, -1); // map from letter to digit
        vector<bool> used(10, false); // whether digit x is used
        return dfs(words, result, maxlen, letters, used, 0, 0);
    }

private:
    bool dfs(const vector<string>& words, const string& result, int maxlen,
             vector<int>& letters, vector<bool>& used, int p, int index){

        if(index == maxlen) return true;

        // if p == words.size(), check result
        if(p == words.size()){

            int res = 0;
            for(const string& word: words){
                int num = 0;
                for(int i = 0; i < min(index + 1, (int)word.size()); i ++)
                    num += letters[word[i] - 'A'] * pow10[i];
                res += num;
            }

            string res_str = to_string(res);

            reverse(res_str.begin(), res_str.end());
            int x = index < res_str.size() ? res_str[index] - '0' : 0;

            if(letters[result[index] - 'A'] != -1){
                if(letters[result[index] - 'A'] != x) return false;
                return dfs(words, result, maxlen, letters, used, 0, index + 1);
            }

            if(used[x]) return false;

            if(x == 0 && leading_letters.count(result[index])) return false;

            letters[result[index] - 'A'] = x;
            used[x] = true;
            if(dfs(words, result, maxlen, letters, used, 0, index + 1)) return true;
            letters[result[index] - 'A'] = -1;
            used[x] = false;
            return false;
        }

        if(index >= words[p].size() || letters[words[p][index] - 'A'] != -1)
            return dfs(words, result, maxlen, letters, used, p + 1, index);

        for(int i = 0; i < 10; i ++)
            if(!used[i]){

                if(i == 0 && leading_letters.count(words[p][index])) continue;

                letters[words[p][index] - 'A'] = i;
                used[i] = true;

                if(dfs(words, result, maxlen, letters, used, p + 1, index)) return true;

                letters[words[p][index] - 'A'] = -1;
                used[i] = false;
            }
        return false;
    }
};


int main() {

    vector<string> words1 = {"SEND", "MORE"};
    cout << Solution().isSolvable(words1, "MONEY") << endl;
    // 1

    vector<string> words2 = {"SIX","SEVEN","SEVEN"};
    cout << Solution().isSolvable(words2, "TWENTY") << endl;
    // 1

    vector<string> words3 = {"THIS","IS","TOO"};
    cout << Solution().isSolvable(words3, "FUNNY") << endl;
    // 1

    vector<string> words4 = {"LEET","CODE"};
    cout << Solution().isSolvable(words4, "POINT") << endl;
    // 0

    return 0;
}
