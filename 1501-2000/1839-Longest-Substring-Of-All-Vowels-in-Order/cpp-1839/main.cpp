/// Source : https://leetcode.com/problems/longest-substring-of-all-vowels-in-order/
/// Author : liuyubobobo
/// Time   : 2021-04-24

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Split
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int longestBeautifulSubstring(string word) {

        int res = 0;
        for(int start = 0, i = start + 1; i <= word.size(); i ++)
            if(i == word.size() || word[i] < word[i - 1]){

                vector<bool> set(26, false);
                for(int j = start; j < i; j ++) set[word[j] - 'a'] = true;
                if(accumulate(set.begin(), set.end(), 0) == 5)
                    res = max(res, i - start);

                start = i;
                i = start;
            }

        return res;
    }
};


int main() {

    cout << Solution().longestBeautifulSubstring("aeiaaioaaaaeiiiiouuuooaauuaeiu") << endl;
    // 13

    cout << Solution().longestBeautifulSubstring("aeeeiiiioooauuuaeiou") << endl;
    // 5

    cout << Solution().longestBeautifulSubstring("a") << endl;
    // 0

    return 0;
}
