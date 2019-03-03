/// Source : https://leetcode.com/problems/find-common-characters/
/// Author : liuyubobobo
/// Time   : 2019-03-03

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;


/// Using HashMap to get the intersection of every two strings
/// Time Complexity: O(n * ave_len_of_strings)
/// Space Complexity: O(26)
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {

        vector<unordered_map<char, int>> freqs(A.size());
        for(int i = 0; i < A.size(); i ++)
            for(char c: A[i])
                freqs[i][c] ++;

        unordered_map<char, int> res = freqs[0];
        for(int i = 1; i < freqs.size(); i ++)
            res = intersection(res, freqs[i]);

        vector<string> ret;
        for(const pair<char, int>& p: res)
            for(int i = 0; i < p.second; i ++)
                ret.push_back(string(1, p.first));
        return ret;
    }

private:
    unordered_map<char, int> intersection(unordered_map<char, int>& freq1,
                                          unordered_map<char, int>& freq2){

        unordered_map<char, int> res;
        for(const pair<char, int>& p: freq1)
            if(freq2.count(p.first))
                res[p.first] = min(p.second, freq2[p.first]);
        return res;
    }
};


int main() {

    return 0;
}