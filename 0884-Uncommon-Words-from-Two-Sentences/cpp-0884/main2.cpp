/// Source : https://leetcode.com/problems/uncommon-words-from-two-sentences/description/
/// Author : liuyubobobo
/// Time   : 2018-08-12

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Uncommon words only occur once
/// Using just one HashMap
///
/// Time Complexity: O(len(A) + len(B))
/// Space Complexity: O(len(A) + len(B))
class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {

        unordered_map<string, int> freq;
        getFreq(freq, A);
        getFreq(freq, B);

        vector<string> res;
        for(const pair<string, int>& p: freq)
            if(p.second == 1)
                res.push_back(p.first);
        return res;
    }

private:
    void getFreq(unordered_map<string, int>& freq, const string& s){

        int start = 0;
        for(int i = start + 1; i <= s.size(); )
            if(i == s.size() || s[i] == ' '){
                freq[s.substr(start, i - start)] ++;
                start = i + 1;
                i = start + 1;
            }
            else
                i ++;
        return;
    }
};


int main() {

    return 0;
}