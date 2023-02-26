/// Source : https://leetcode.com/problems/maximum-score-words-formed-by-letters/description/
/// Author : liuyubobobo
/// Time   : 2023-02-25

#include <iostream>
#include <vector>

using namespace std;


/// State Compression DP
/// Time Complexity: O(2^n * max_word_len)
/// Space Complexity: O(1)
class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {

        int n = words.size();

        vector<int> f(26, 0);
        for(char c: letters) f[c - 'a'] ++;

        int res = 0;
        for(int state = 0; state < (1 << n); state ++){

            vector<int> curf(26, 0);
            for(int i = 0; i < n; i ++){
                if((state >> i) & 1) for(char c: words[i]) curf[c - 'a'] ++;
            }

            if(ok(curf, f)){
                int cur_score = 0;
                for(int i = 0; i < 26; i ++) cur_score += score[i] * curf[i];
                res = max(res, cur_score);
            }
        }
        return res;
    }

private:
    bool ok(const vector<int>& v, const vector<int>& f){
        for(int i = 0; i < 26; i ++) if(v[i] > f[i]) return false;
        return true;
    }
};


int main() {

    return 0;
}
