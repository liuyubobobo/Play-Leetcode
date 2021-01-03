/// Source : https://leetcode.com/problems/palindrome-permutation-ii/
/// Author : liuyubobobo
/// Time   : 2020-01-01

#include <iostream>
#include <vector>

using namespace std;


/// Backtrack
/// Time Complexity: O((|s| / 2)^(|s| / 2))
/// Space Complexity: O(|s|)
class Solution {
public:
    vector<string> generatePalindromes(string s) {

        vector<int> freq(256, 0);
        for(char c: s)
            freq[c] ++;

        int even = 0, odd = 0;
        char oddchar = 0;
        for(int ch = 0; ch < freq.size(); ch ++)
            if(freq[ch] % 2)
                odd ++, oddchar = ch;
            else even ++;

        if(odd > 1) return {};

        string cur(s.size(), oddchar);
        if(oddchar) freq[oddchar] --;
        vector<string> res;
        dfs(freq, 0, cur, res);
        return res;
    }

private:
    void dfs(vector<int>& freq, int index, string& cur, vector<string>& res){

        if(index >= cur.size() / 2){
            res.push_back(cur);
            return;
        }

        for(char ch = 0; ch < freq.size(); ch ++)
            if(freq[ch]){
                cur[index] = cur[cur.size() - index - 1] = ch;
                freq[ch] -= 2;
                dfs(freq, index + 1, cur, res);
                freq[ch] += 2;
            }
    }
};


int main() {

    return 0;
}
