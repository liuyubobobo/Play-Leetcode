/// Source : https://leetcode.com/problems/uncommon-words-from-two-sentences/description/
/// Author : liuyubobobo
/// Time   : 2018-08-11

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Simulation uncommon words concepts
/// Using Two HashMaps
///
/// Time Complexity: O(len(A) + len(B))
/// Space Complexity: O(len(A) + len(B))
class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {

        unordered_map<string, int> freqA = getFreq(A);
        unordered_map<string, int> freqB = getFreq(B);

        vector<string> res;
        for(const pair<string, int>& p: freqA)
            if(p.second == 1 && freqB.find(p.first) == freqB.end())
                res.push_back(p.first);
        for(const pair<string, int>& p: freqB)
            if(p.second == 1 && freqA.find(p.first) == freqA.end())
                res.push_back(p.first);
        return res;
    }

private:
    unordered_map<string, int> getFreq(const string& s){

        unordered_map<string, int> freq;
        int start = 0;
        for(int i = start + 1; i <= s.size(); )
            if(i == s.size() || s[i] == ' '){
                freq[s.substr(start, i - start)] ++;
                start = i + 1;
                i = start + 1;
            }
            else
                i ++;
        return freq;
    }
};


int main() {

    return 0;
}