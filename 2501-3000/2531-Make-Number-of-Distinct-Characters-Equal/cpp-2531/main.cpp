/// Source : https://leetcode.com/problems/make-number-of-distinct-characters-equal/description/
/// Author : liuyubobobo
/// Time   : 2023-01-08

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(|word1| + |word2| + CHAR_SET^3)
/// Space Complexity: O(1)
class Solution {
public:
    bool isItPossible(string word1, string word2) {

        vector<int> f1(26, 0), f2(26, 0);
        for(char c: word1) f1[c - 'a'] ++;
        for(char c: word2) f2[c - 'a'] ++;

        for(int i = 0; i < 26; i ++) if(f1[i])
            for(int j = 0; j < 26; j ++) if(f2[j]){
                f1[i] --, f2[j] --;
                f1[j] ++, f2[i] ++;

                if(get_unique(f1) == get_unique(f2)) return true;

                f1[j] --, f2[i] --;
                f1[i] ++, f2[j] ++;
            }
        return false;
    }

private:
    int get_unique(const vector<int>& f){

        int res = 0;
        for(int e: f) res += !!e;
        return res;
    }
};

int main() {

    return 0;
}
