/// Source : https://leetcode.com/problems/group-anagrams/description/
/// Author : liuyubobobo
/// Time   : 2018-09-12

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Using HashMap
/// Using sorted string as key
///
/// Time Complexity: O(n*klogk) where k is the max length of string in strs
/// Space Complexity: O(n*k)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> map;
        for(const string& s: strs){
            string key = s;
            sort(key.begin(), key.end());
            map[key].push_back(s);
        }

        vector<vector<string>> res;
        for(const auto& p: map)
            res.push_back(p.second);
        return res;
    }
};


int main() {

    return 0;
}