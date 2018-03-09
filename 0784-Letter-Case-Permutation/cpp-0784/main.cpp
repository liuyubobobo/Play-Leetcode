/// Source : https://leetcode.com/problems/letter-case-permutation/description/
/// Author : liuyubobobo
/// Time   : 2018-03-09

#include <iostream>
#include <vector>
#include <cassert>
#include <ctype.h>

using namespace std;

/// Backtrack
///
/// Time Complexity: O(2^len(S))
/// Space Complexity: O(len(S))
class Solution {

public:
    vector<string> letterCasePermutation(string S) {

        for(int i = 0 ; i < S.size() ; i ++)
            if(isupper(S[i]))
                S[i] = tolower(S[i]);

        vector<string> res;
        solve(S, 0, res);
        return res;
    }

private:
    void solve(string& S, int index, vector<string>& res){

        if(index == S.size()){
            res.push_back(S);
            return;
        }

        if(isalpha(S[index])){
            assert(islower(S[index]));
            solve(S, index + 1, res);
            S[index] = toupper(S[index]);
            solve(S, index + 1, res);
            S[index] = tolower(S[index]);
        }
        else{
            assert(isdigit(S[index]));
            solve(S, index + 1, res);
        }
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