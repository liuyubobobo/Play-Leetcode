/// Source : https://leetcode.com/problems/decoded-string-at-index/description/
/// Author : liuyubobobo
/// Time   : 2018-08-04
#include <iostream>
#include <cassert>

using namespace std;


/// Recursion
/// Time Complexity: O(len(S)*logK)
/// Space Complexity: O(logK)
class Solution {
public:
    string decodeAtIndex(string S, int K) {

        int curl = 0;
        int repeat = 1;
        for(char c: S){
            if(isalpha(c)){
                if(curl * repeat + 1 == K)
                    return string(1, c);
                curl = curl * repeat + 1;
                repeat = 1;
            }
            else{
                repeat *= (c - '0');
                if((long long)K <= (long long)curl * (long long)repeat)
                    return decodeAtIndex(S, (K - 1) % curl + 1);
            }
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