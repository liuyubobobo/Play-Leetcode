/// Source : https://leetcode.com/problems/prefix-and-suffix-search/
/// Author : liuyubobobo
/// Time   : 2022-07-14

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


/// Using Hash + Map
/// Time Complexity: init: O(|words| * len^2)
///                  query: O(|prefix| + |suffix|)
/// Space Complexity: O(|words| * len^2)
class WordFilter {

private:
    map<pair<long long, long long>, int> table;

public:
    WordFilter(vector<string> words) {

        for(int i = 0 ; i < words.size() ; i ++)
            insert(words[i], i);

    }

    int f(string prefix, string suffix) {

        long long pre_hash = 0;
        for(int i = 0; i < prefix.size(); i ++)
            pre_hash = pre_hash * 27 + (prefix[i] - 'a' + 1);

        long long suf_hash = 0;
        for(int i = suffix.size() - 1; i >= 0; i --)
            suf_hash = suf_hash * 27 + (suffix[i] - 'a' + 1);

        auto iter = table.find({pre_hash, suf_hash});
        return iter == table.end() ? -1 : iter->second;
    }

private:
    void insert(const string& s, int index){

        long long pre_hash = 0;
        for(int i = 0; i < s.size(); i ++){
            pre_hash = pre_hash * 27 + (s[i] - 'a' + 1);

            long long suf_hash = 0;
            for(int i = s.size() - 1; i >= 0; i --){
                suf_hash = suf_hash * 27 + (s[i] - 'a' + 1);
                table[{pre_hash, suf_hash}] = index;
            }
        }
    }
};


int main() {

    return 0;
}
