/// Source : https://leetcode.com/problems/substring-with-concatenation-of-all-words/
/// Author : liuyubobobo
/// Time   : 2022-06-22

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Sliding Window
/// Time Complexity: O(word_len * |s|)
/// Space Complexity: O(|s|)
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        int word_len = words[0].size();

        map<string, int> words_f;
        for(int i = 0; i < words.size(); i ++) words_f[words[i]] ++;

        vector<int> res;
        for(int start = 0; start < word_len; start ++){

            vector<string> data;
            for(int i = start; i < s.size(); i += word_len)
                data.push_back(s.substr(i, word_len));

            int ok_cnt = 0, l = 0, r = -1;
            map<string, int> cur_f;
            while(l < (int)data.size()){
                if(r + 1 < (int)data.size() && words_f.count(data[r + 1]) && cur_f[data[r + 1]] + 1 <= words_f[data[r + 1]]){
                    cur_f[data[r + 1]] ++;

                    if(cur_f[data[r + 1]] == words_f[data[r + 1]]){
                        ok_cnt ++;
                        if(ok_cnt == words_f.size())
                            res.push_back(start + l * word_len);
                    }

                    r ++;
                }
                else{

                    if(words_f.count(data[l])){
                        cur_f[data[l]] --;
                        if(cur_f[data[l]] + 1 == words_f[data[l]]) ok_cnt --;
                    }
                    l ++;
                    r = max(r, l - 1);
                }
            }
        }

        return res;
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << ' '; cout << '\n';
}

int main() {

    vector<string> words1 = {"foo", "bar"};
    print_vec(Solution().findSubstring("barfoothefoobarman", words1));
    // 0 9

    vector<string> words2 = {"word","good","best","word"};
    print_vec(Solution().findSubstring("wordgoodgoodgoodbestword", words2));
    // empty

    vector<string> words3 = {"bar","foo","the"};
    print_vec(Solution().findSubstring("barfoofoobarthefoobarman", words3));
    // 6 9 12

    return 0;
}
