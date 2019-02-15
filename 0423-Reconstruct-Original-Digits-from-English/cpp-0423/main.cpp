/// Source : https://leetcode.com/problems/reconstruct-original-digits-from-english/
/// Author : liuyubobobo
/// Time   : 2019-02-14

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    string originalDigits(string s) {

        vector<int> freq(26);
        for(char c: s)
            freq[c - 'a'] ++;

        string res = "";

        res += check(freq, "zero", 'z', '0');
        res += check(freq, "two", 'w', '2');
        res += check(freq, "four", 'u', '4');
        res += check(freq, "six", 'x', '6');
        res += check(freq, "eight", 'g', '8');

        res += check(freq, "one", 'o', '1');
        res += check(freq, "three", 'r', '3');
        res += check(freq, "five", 'f', '5');
        res += check(freq, "seven", 'v', '7');
        res += check(freq, "nine", 'i', '9');

        sort(res.begin(), res.end());
        return res;
    }

private:
    string check(vector<int>& freq, const string& s, char base, char res){

        int num = freq[base - 'a'];
        for(char c: s){
            freq[c - 'a'] -= num;
            assert(freq[c - 'a'] >= 0);
        }
        return string(num, res);
    }
};


int main() {

    return 0;
}