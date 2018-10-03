/// Source : https://leetcode.com/problems/group-shifted-strings/description/
/// Author : liuyubobobo
/// Time   : 2018-10-03

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;


/// Using HashMap
/// Time Complexity: O(n * average len of s)
/// Space Compleity: O(n * average len of s)
class Solution {

public:
    vector<vector<string>> groupStrings(vector<string>& strings) {

        unordered_map<string, vector<string>> map;
        for(const string& s: strings){
            string key = getKey(s);
            map[key].push_back(s);
        }

        vector<vector<string>> res;
        for(const pair<string, vector<string>>& p: map)
            res.push_back(p.second);
        return res;
    }

private:
    string getKey(string s){

        int dis = 26 - (s[0] - 'a');
        for(int i = 0; i < s.size(); i ++)
            s[i] = 'a' + (s[i] + dis) % 26;
        return s;
    }
};


int main() {

    return 0;
}