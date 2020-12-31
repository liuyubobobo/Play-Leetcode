/// Source : https://leetcode.com/problems/number-of-valid-words-for-each-puzzle/
/// Author : liuyubobobo
/// Time   : 2019-08-31

#include <iostream>
#include <vector>

using namespace std;


/// Bit-Compression + Brute Force
/// Time Complexity: O(|words| * |puzzles|)
/// Space Complexity: O(|words|)
class Solution {

private:
    vector<int> v;

public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {

        for(const string& word: words){
            int hash = gethash(word);
            int b = bitnum(hash);
            if(b <= 7) v.push_back(hash);
        }

        vector<int> res;
        for(const string& puzzle: puzzles){
            int hash = gethash(puzzle), r = 0;
            for(int e: v)
                if((e | hash) == hash && (e & (1 << (puzzle[0] - 'a'))))
                    r ++;
            res.push_back(r);
        }
        return res;
    }

private:
    int gethash(const string& s){
        int hash = 0;
        for(char c: s)
            hash |= (1 << (c - 'a'));
        return hash;
    }

    int bitnum(int hash){
        int res = 0;
        for(int i = 0; i < 26; i ++)
            res += ((hash & (1 << i)) != 0);
        return res;
    }
};


void print_vec(const vector<int>& vec){
    for(int e: vec) cout << e << " "; cout << endl;
}

int main() {

    vector<string> words1 = {"aaaa","asas","able","ability","actt","actor","access"};
    vector<string> puzzles1 = {"aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"};
    print_vec(Solution().findNumOfValidWords(words1, puzzles1));
    // 1,1,3,2,4,0

    vector<string> words2 = {"apple","pleas","please"};
    vector<string> puzzles2 = {"aelwxyz","aelpxyz","aelpsxy","saelpxy","xaelpsy"};
    print_vec(Solution().findNumOfValidWords(words2, puzzles2));
    // 0,1,3,2,0

    return 0;
}