/// Source : https://leetcode.com/problems/di-string-match/
/// Author : liuyubobobo
/// Time   : 2018-11-17

#include <iostream>
#include <vector>

using namespace std;


/// Generating the result from 0
/// Adding the offset at last
///
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> diStringMatch(string S) {

        int n = S.size();
        vector<int> res(n + 1, 0);

        int minv = 0, maxv = 0;
        for(int i = 0; i < S.size(); i ++){
            int x;
            if(S[i] == 'I')
                x = ++maxv;
            else
                x = --minv;

            res[i + 1] = x;
        }

        for(int& e: res)
            e += -minv;
        return res;
    }
};


void print_vec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    string S1 = "IDID";
    print_vec(Solution().diStringMatch(S1));

    return 0;
}