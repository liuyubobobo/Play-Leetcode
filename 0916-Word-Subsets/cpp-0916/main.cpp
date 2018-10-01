/// Source : https://leetcode.com/problems/word-subsets/description/
/// Author : liuyubobobo
/// Time   : 2018-09-30

#include <iostream>
#include <vector>

using namespace std;


/// Reduce set B into a single word b
/// Time Complexity: O(A.size() + B.size())
/// Space Complexity: O(26)
class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {

        vector<int> b = getFreq(B[0]);
        for(int i = 1; i < B.size(); i ++){
            vector<int> tb = getFreq(B[i]);
            for(int j = 0; j < 26; j ++)
                b[j] = max(b[j], tb[j]);
        }

        vector<string> res;
        for(const string& word: A){
            vector<int> a = getFreq(word);
            if(contains(a, b))
                res.push_back(word);
        }
        return res;
    }

private:
    vector<int> getFreq(const string& word){
        vector<int> freq(26, 0);
        for(char c: word)
            freq[c - 'a'] ++;
        return freq;
    }

    bool contains(const vector<int>& a, const vector<int>& b){
        for(int i = 0; i < 26; i ++)
            if(a[i] < b[i])
                return false;
        return true;
    }
};


int main() {

    return 0;
}