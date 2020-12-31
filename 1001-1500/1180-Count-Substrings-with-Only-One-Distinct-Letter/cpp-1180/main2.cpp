/// Source : https://leetcode.com/problems/count-substrings-with-only-one-distinct-letter/
/// Author : liuyubobobo
/// Time   : 2019-09-07

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int countLetters(string S) {

        vector<int> res(S.size(), 1);
        for(int i = 1; i < S.size(); i ++)
            if(S[i] == S[i - 1]) res[i] += res[i - 1];
        return accumulate(res.begin(), res.end(), 0);
    }
};


int main() {

    cout << Solution().countLetters("aaaba") << endl;
    // 8

    cout << Solution().countLetters("aaaaaaaaaa") << endl;
    // 55

    return 0;
}