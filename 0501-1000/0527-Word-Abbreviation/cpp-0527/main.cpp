/// Source : https://leetcode.com/problems/word-abbreviation/
/// Author : liuyubobobo
/// Time   : 2022-06-14

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Hash Map + Simulation
/// Time Complexity: O(len * 26^2 + nlogn + n * len^2)
/// Space Compelxity: O(len * 26^2 + n)
class Solution {
public:
    vector<string> wordsAbbreviation(const vector<string>& words) {

        int n = words.size();

        vector<string> res(n, "");

        vector<int> table[26][26][401];
        for(int i = 0; i < n; i ++){
            const string& word = words[i];
            table[word[0] - 'a'][word.back() - 'a'][word.size()].push_back(i);
        }

        for(int first = 0; first < 26; first ++)
            for(int last = 0; last < 26; last ++)
                for(int len = 2; len <= 400; len ++){
                    const vector<int>& v = table[first][last][len];
                    if(v.empty()) continue;
                    if(v.size() == 1){
                        res[v[0]] = get_abbr(words[v[0]], 0);
                        continue;
                    }

                    vector<pair<string, int>> data(v.size());
                    for(int i = 0; i < v.size(); i ++) data[i] = {words[v[i]], v[i]};
                    sort(data.begin(), data.end());

                    for(int i = 0; i < data.size(); i ++){
                        const string& word = data[i].first;
                        int index = data[i].second;

                        for(int prefix_len = 2;; prefix_len ++){
                            bool ok1 = i - 1 < 0 || word.substr(0, prefix_len) != data[i - 1].first.substr(0, prefix_len);
                            bool ok2 = i + 1 >= data.size() || word.substr(0, prefix_len) != data[i + 1].first.substr(0, prefix_len);
                            if(ok1 && ok2){
                                res[index] = get_abbr(word, prefix_len - 1);
                                break;
                            }
                        }
                        assert(res[index] != "");
                    }
                }
        return res;
    }

private:
    // [0...prefix_end_index] + num + last_character
    string get_abbr(const string& s, int prefix_end_index){

        string res = s.substr(0, prefix_end_index + 1);
        int len = s.size() - (prefix_end_index + 2);
        if(len) res += to_string(len);
        res += s.back();

        return res.size() < s.size() ? res : s;
    }
};


void print_vec(const vector<string>& res){
    for(const string& e: res) cout << e << ' '; cout << '\n';
}

int main() {

    vector<string> words1 = {"like","god","internal","me","internet","interval","intension","face","intrusion"};
    print_vec(Solution().wordsAbbreviation(words1));
    // ["l2e","god","internal","me","i6t","interval","inte4n","f2e","intr4n"]

    vector<string> words2 = {"abcdefg","abccefg","abcckkg"};
    print_vec(Solution().wordsAbbreviation(words2));
    // ["abcd2g","abccefg","abcckkg"]

    return 0;
}
