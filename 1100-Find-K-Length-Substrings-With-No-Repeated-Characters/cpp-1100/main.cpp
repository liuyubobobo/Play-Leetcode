/// Source : https://leetcode.com/problems/find-k-length-substrings-with-no-repeated-characters/
/// Author : liuyubobobo
/// Time   : 2019-06-29

#include <iostream>
#include <vector>

using namespace std;


/// Two Pointers
/// Time Complexity: O(26n)
/// Space Complexity: O(1)
class Solution {
public:
    int numKLenSubstrNoRepeats(string S, int K) {

        if(S.size() < K) return 0;

        vector<int> freq(26, 0);
        for(int i = 0; i < K - 1; i ++)
            freq[S[i] - 'a'] ++;

        int res = 0;
        for(int i = K - 1; i < S.size(); i ++){
            freq[S[i] - 'a'] ++;
            if(ok(freq)) res ++;
            freq[S[i - (K - 1)] - 'a'] --;
        }
        return res;
    }

private:
    bool ok(const vector<int>& freq){
        for(int e: freq)
            if(e > 1) return false;
        return true;
    }
};


int main() {

    return 0;
}