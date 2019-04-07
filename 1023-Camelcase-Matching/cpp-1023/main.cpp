/// Source : https://leetcode.com/problems/camelcase-matching/
/// Author : liuyubobobo
/// Time   : 2019-04-06

#include <iostream>
#include <vector>

using namespace std;


/// Greedy
/// Time Complexity: O(n * len(|q|))
/// Space Complexity: O(1)
class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {

        vector<bool> res;
        for(const string& s : queries)
            res.push_back(ok(s, pattern));
        return res;
    }

private:
    bool ok(const string& s, const string& p){

        int i = 0;
        for(char c: s)
            if(c == p[i]) i ++;
            else if(isupper(c)) return false;
        return i == p.size();
    }
};


int main() {

    return 0;
}