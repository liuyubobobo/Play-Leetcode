/// Source : https://leetcode.com/problems/letter-case-permutation/description/
/// Author : liuyubobobo
/// Time   : 2018-03-09

#include <iostream>
#include <vector>
#include <cassert>
#include <ctype.h>

using namespace std;

/// Binary Code
///
/// Time Complexity: O(2^len(S))
/// Space Complexity: O(len(S))
class Solution {

public:
    vector<string> letterCasePermutation(string S) {

        int n = 0;
        for(int i = 0 ; i < S.size() ; i ++)
            if(isalpha(S[i])){
                S[i] = tolower(S[i]);
                n ++;
            }

        vector<string> res;
        for(int i = 0 ; i < (1<<n) ; i ++){

            int k = 0;
            for(int j = 0 ; j < S.size() ; j ++)
                if(isalpha(S[j])){
                    if(i & (1<<k))
                        S[j] = toupper(S[j]);
                    else
                        S[j] = tolower(S[j]);
                    k ++;
                }
            res.push_back(S);
        }
        return res;
    }
};


void print_vec(const vector<string>& vec){
    for(string s: vec)
        cout << s << " ";
    cout << endl;
}

int main() {

    print_vec(Solution().letterCasePermutation("a1b2"));
    cout << endl;

    print_vec(Solution().letterCasePermutation("3z4"));
    cout << endl;

    print_vec(Solution().letterCasePermutation("12345"));
    cout << endl;

    return 0;
}