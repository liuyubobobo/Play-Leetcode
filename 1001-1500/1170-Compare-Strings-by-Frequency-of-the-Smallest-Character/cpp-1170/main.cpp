/// Source : https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/
/// Author : liuyubobobo
/// Time   : 2019-08-24

#include <iostream>
#include <vector>

using namespace std;


/// Presum
/// Time Complexity: O(|words| + |queries|)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {

        vector<int> vec(11, 0);
        for(const string& word: words)
            vec[f(word)] ++;

        for(int i = vec.size() - 1; i >= 1; i --)
            vec[i - 1] += vec[i];

        vector<int> res;
        for(const string& q: queries)
            res.push_back(vec[f(q) + 1]);
        return res;
    }

private:
    int f(const string& s){
        vector<int> freq(26, 0);
        for(char c: s)
            freq[c - 'a'] ++;
        for(int e: freq) if(e) return e;
        return 0;
    }
};


void print_vec(const vector<int>& vec){
    for(int e: vec) cout << e << " "; cout << endl;
}

int main() {

    vector<string> queries1 = {"cbd"}, words1 = {"zaaaz"};
    print_vec(Solution().numSmallerByFrequency(queries1, words1));
    // {1}

    vector<string> queries2 = {"bbb","cc"}, words2 = {"a","aa","aaa","aaaa"};
    print_vec(Solution().numSmallerByFrequency(queries2, words2));
    // {1, 2}

    return 0;
}