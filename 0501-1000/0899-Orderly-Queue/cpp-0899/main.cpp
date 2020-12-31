/// Source : https://leetcode.com/problems/orderly-queue/description/
/// Author : liuyubobobo
/// Time   : 2018-09-02

#include <iostream>

using namespace std;


/// Mathematic
/// When K = 1, solve it brutely
/// When K = 2, we can get any permutation of the S
/// When K > 2, we can also get any permutation of the S
///
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    string orderlyQueue(string S, int K) {

        if(K == 1){
            string ret = S;
            for(int len = 1; len  < S.size(); len ++){
                string t_ret = S.substr(len) + S.substr(0, len);
                if(t_ret < ret)
                    ret = t_ret;
            }
            return ret;
        }

        sort(S.begin(), S.end());
        return S;
    }
};


int main() {

    return 0;
}