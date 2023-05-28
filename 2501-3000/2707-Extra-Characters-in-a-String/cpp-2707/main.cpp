/// Source : https://leetcode.com/problems/extra-characters-in-a-string/
/// Author : liuyubobobo
/// Time   : 2023-05-27

#include <iostream>
#include <vector>

using namespace std;


/// DP
/// Time Complexity: O(n * all_word_length)
/// Space Complexity: O(n)
class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {

        int n = s.size();
        vector<int> dp(n + 1, 0);
        for(int i = n - 1; i >= 0; i --){
            dp[i] = dp[i + 1];
            for(const string& word: dictionary)
                if(s.find(word, i) == i)
                    dp[i] = max(dp[i], (int)word.size() + dp[i + word.size()]);
        }

        return n - *max_element(dp.begin(), dp.end());
    }
};


int main() {

    return 0;
}
