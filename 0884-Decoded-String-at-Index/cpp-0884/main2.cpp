/// Source : https://leetcode.com/problems/decoded-string-at-index/description/
/// Author : liuyubobobo
/// Time   : 2018-08-05
#include <iostream>
#include <cassert>

using namespace std;


/// Backwards iteration
/// Time Complexity: O(len(S))
/// Space Complexity: O(1)
class Solution {
public:
    string decodeAtIndex(string S, int K) {

        long long curl = 0ll;
        long long repeat = 1ll;
        for(char c: S)
            if(isalpha(c)){
                curl *= repeat, curl += 1ll;
                repeat = 1ll;
            }
            else
                repeat *= (long long)(c - '0');
        curl *= repeat;

        for(int i = S.size() - 1; i >= 0; i --)
            if(isalpha(S[i])){
                if(K == curl)
                    return string(1, S[i]);
                curl --;
            }
            else{
                curl /= (long long)(S[i] - '0');
                K = (int)((long long)(K - 1) % curl + 1ll);
            }

        assert(false);
        return "";
    }
};


int main() {

    string S1 = "leet2code3";
    cout << Solution().decodeAtIndex(S1, 10) << endl; // o

    string S2 = "ha22";
    cout << Solution().decodeAtIndex(S2, 5) << endl; // h

    string S3 = "a2345678999999999999999";
    cout << Solution().decodeAtIndex(S3, 1) << endl; // a

    return 0;
}