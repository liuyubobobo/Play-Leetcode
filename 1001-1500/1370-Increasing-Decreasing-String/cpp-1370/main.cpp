/// Source : https://leetcode.com/problems/increasing-decreasing-string/
/// Author : liuyubobobo
/// Time   : 2020-03-07

#include <iostream>
#include <vector>

using namespace std;


/// Hash Map
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    string sortString(string s) {

        vector<int> freq(26, 0);
        for(char c: s) freq[c - 'a'] ++;

        string res = "";
        while(res.size() != s.size()){
            for(int i = 0; i < 26; i ++)
                if(freq[i]) res += ('a' + i), freq[i] --;
            for(int i = 25; i >= 0; i --)
                if(freq[i]) res += ('a' + i), freq[i] --;
        }
        return res;
    }
};


int main() {

    return 0;
}
