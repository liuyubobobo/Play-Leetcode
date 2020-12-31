/// Source : https://leetcode.com/problems/group-anagrams/description/
/// Author : liuyubobobo
/// Time   : 2018-09-12

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Using HashMap
/// Using characters frequency as key
///
/// Time Complexity: O(n*k) where k is the max length of string in strs
/// Space Complexity: O(n*k)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> map;
        for(const string& s: strs){
            string key = getKey(s);
            map[key].push_back(s);
        }

        vector<vector<string>> res;
        for(const auto& p: map)
            res.push_back(p.second);
        return res;
    }

private:
    string getKey(const string& s){
        vector<int> freq(26, 0);
        for(char c: s)
            freq[c - 'a'] ++;
        string key = "";
        for(int num: freq)
            key += to_string(num) + "#";
        return key;
    }
};


int main() {

    return 0;
}