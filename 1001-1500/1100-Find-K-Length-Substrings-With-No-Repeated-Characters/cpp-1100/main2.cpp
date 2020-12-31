/// Source : https://leetcode.com/problems/find-k-length-substrings-with-no-repeated-characters/
/// Author : liuyubobobo
/// Time   : 2019-07-07

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/// Two Pointers and use a unordered_set to record all repeats characters
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int numKLenSubstrNoRepeats(string S, int K) {

        if(S.size() < K) return 0;

        vector<int> freq(26, 0);
        unordered_set<char> repeats;
        for(int i = 0; i < K - 1; i ++){
            freq[S[i] - 'a'] ++;
            if(freq[S[i] - 'a'] > 1)
                repeats.insert(S[i]);
        }

        int res = 0;
        for(int i = K - 1; i < S.size(); i ++){
            freq[S[i] - 'a'] ++;
            if(freq[S[i] - 'a'] > 1) repeats.insert(S[i]);

            if(!repeats.size()) res ++;

            freq[S[i - (K - 1)] - 'a'] --;
            if(freq[S[i - (K - 1)] - 'a'] <= 1)
                repeats.erase(S[i - (K - 1)]);
        }
        return res;
    }
};


int main() {

    cout << Solution().numKLenSubstrNoRepeats("havefunonleetcode", 5) << endl;
    // 6

    return 0;
}