/// Source : https://leetcode.com/problems/largest-merge-of-two-strings/
/// Author : liuyubobobo
/// Time   : 2021-02-06

#include <iostream>
#include <vector>

using namespace std;


/// Greedy
/// Time Complexity: O((m + n) * max(m, n))
/// Space Complexity: O(max(m, n))
class Solution {
public:
    string largestMerge(string word1, string word2) {

        int n = word1.size(), m = word2.size();

        string res = "";
        int i = 0, j = 0;
        while(i <= n && j <= m){
            if(i == n){
                res += word2.substr(j);
                break;
            }
            else if(j == m){
                res += word1.substr(i);
                break;
            }
            else if(word1[i] > word2[j])
                res += word1[i], i ++;
            else if(word1[i] < word2[j])
                res += word2[j], j ++;
            else if(greater(word1, i + 1, word2, j + 1))
                res += word1[i], i ++;
            else
                res += word2[j], j ++;
        }
        return res;
    }

private:
    bool greater(const string& s1, int i, const string& s2, int j){

        while(i < s1.size() && j < s2.size())
            if(s1[i] != s2[j]) return s1[i] > s2[j];
            else i ++, j ++;
        return i < s1.size();
    }
};


int main() {

    cout << Solution().largestMerge("cabaa", "bcaaa") << endl;
    // "cbcabaaaaa"

    cout << Solution().largestMerge("abcabc", "abdcaba") << endl;
    // "abdcabcabcaba"

    cout << Solution().largestMerge("abc", "abd") << endl;
    // "abdabc"

    return 0;
}
