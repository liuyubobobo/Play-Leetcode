/// Source : https://leetcode.com/problems/count-vowel-substrings-of-a-string/
/// Author : liuyubobobo
/// Time   : 2021-11-06

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Brute Force
/// Time Co,plexity: O(n^3)
/// Space Complexity: O(1)
class Solution {
public:
    int countVowelSubstrings(string word) {

        int n = word.size(), res = 0;
        for(int i = 0; i < n; i ++)
            for(int j = i; j < n; j ++)
                res += check(word.substr(i, j - i + 1));
        return res;
    }

private:
    bool check(const string& s){

        if(s.size() < 5) return false;

        vector<int> f(26, 0);
        int cnt = 0;
        for(char c: s){
            if(c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u')
                return false;
            f[c - 'a'] ++;
            cnt += f[c - 'a'] == 1;
        }
        return cnt == 5;
    }
};


int main() {

    return 0;
}
