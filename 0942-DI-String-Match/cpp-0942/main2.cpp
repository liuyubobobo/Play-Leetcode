/// Source : https://leetcode.com/problems/di-string-match/
/// Author : liuyubobobo
/// Time   : 2018-11-17

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/// Generating the result from min value 0 and max value n - 1
///
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> diStringMatch(string S) {

        int n = S.size();
        vector<int> res(n + 1, 0);

        int l = 0, h = n;
        for(int i = 0; i < S.size(); i ++){
            if(S[i] == 'I')
                res[i] = l ++;
            else
                res[i] = h --;
        }

        assert(l == h);
        res.back() = l;
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