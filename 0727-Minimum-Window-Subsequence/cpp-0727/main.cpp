/// Source : https://leetcode.com/contest/weekly-contest-58/problems/minimum-window-subsequence/
/// Author : liuyubobobo
/// Time   : 2017-11-11

#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

/// Memory Search
///
/// !!! Memory Limit Exceed !!!
///
/// Time Complexity: O(len(S)*len(T))
/// Space Complexity: O(len(S)*len(T))

class Solution {

private:
    int MY_MAX_INT = 20001;

public:
    string minWindow(string S, string T) {

        vector<vector<int>> mem(20001, vector<int>(101, -1));

        int min_length = MY_MAX_INT;
        int start = -1;
        for(int i = 0 ; i < S.size() ; i ++){
            search(mem, S, i, T, 0);
            assert(mem[i][0] != -1);
            //cout << mem[i][0] << endl;
            if(mem[i][0] < min_length){
                min_length = mem[i][0];
                start = i;
            }
        }

        for(int i = 0 ; i < S.size() ; i ++){
            for(int j = 0 ; j < T.size() ; j ++)
                cout << mem[i][j] << "\t";
            cout << endl;
        }
        //cout << start << " " << min_length << endl;
        return start == -1 ? "" : S.substr(start, min_length);
        return "";
    }

private:
    int search(vector<vector<int>>& mem,
               const string& S, int i1, const string& T, int i2){

        if(i2 == T.size())
            return 0;

        if(i1 == S.size())
            return MY_MAX_INT;

        if(mem[i1][i2] != -1)
            return mem[i1][i2];

        int res = 1 + search(mem, S, i1+1, T, i2);
        if(S[i1] == T[i2])
            res = min(res, 1 + search(mem, S, i1+1, T, i2+1));
        return mem[i1][i2] = res;
    }
};

int main() {

    string S1 = "abcdebdde";
    string T1 = "bde";
    cout << Solution().minWindow(S1, T1) << endl;

    return 0;
}