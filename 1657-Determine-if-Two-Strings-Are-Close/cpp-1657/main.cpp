/// Source : https://leetcode.com/problems/determine-if-two-strings-are-close/
/// Author : liuyubobobo
/// Time   : 2020-11-14

#include <iostream>
#include <vector>

using namespace std;


/// Using HashMap
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    bool closeStrings(string word1, string word2) {

        if(word1.size() != word2.size()) return false;

        vector<int> f1(26, 0), f2(26, 0);
        for(int i = 0; i < word1.size(); i ++)
            f1[word1[i] - 'a'] ++, f2[word2[i] - 'a'] ++;

        for(int i = 0; i < 26; i ++){
            if(f1[i] && !f2[i]) return false;
            if(f2[i] && !f1[i]) return false;
        }

        sort(f1.begin(), f1.end());
        sort(f2.begin(), f2.end());
        return f1 == f2;
    }
};


int main() {

    cout << Solution().closeStrings("abc", "bca") << endl;
    // 1

    cout << Solution().closeStrings("a", "aa") << endl;
    // 0

    cout << Solution().closeStrings("cabbba", "abbccc") << endl;
    // 1

    cout << Solution().closeStrings("cabbba", "aabbss") << endl;
    // 0

    cout << Solution().closeStrings("uau", "ssx") << endl;
    // 0

    return 0;
}
