/// Source : https://leetcode.com/problems/swap-for-maximum-repeated-substring/
/// Author : liuyubobobo
/// Time   : 2019-08-10

#include <iostream>
#include <vector>

using namespace std;


/// Split and Linear Scan
/// The idea is same as main.cpp but the logic is far more concise
///
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int maxRepOpt1(string text) {

        int n = text.size();
        vector<int> freq(26, 0);
        for(char c: text) freq[c - 'a'] ++;

        vector<string> split;
        for(int start = 0, i = start + 1; i <= n; i ++)
            if(i == n || text[i] != text[start]){
                split.push_back(text.substr(start, i - start));
                start = i;
                i = start;
            }
        int res = 1;
        for(const string& s: split)
            res = max(res, (int)s.size() + (freq[s[0] - 'a'] > s.size()));

        for(int i = 1; i + 1 < split.size(); i ++)
            if(split[i - 1][0] == split[i + 1][0] && split[i].size() == 1){
                int f = freq[split[i - 1][0] - 'a'];
                int sum = split[i - 1].size() + split[i + 1].size();
                res = max(res, sum + (f > sum));
            }
        return res;
    }
};


int main() {

    cout << Solution().maxRepOpt1("ababa") << endl;
    // 3

    cout << Solution().maxRepOpt1("aaabaaa") << endl;
    // 6

    cout << Solution().maxRepOpt1("aaabbaaa") << endl;
    // 4

    cout << Solution().maxRepOpt1("aaaaa") << endl;
    // 5

    cout << Solution().maxRepOpt1("abcdef") << endl;
    // 1

    cout << Solution().maxRepOpt1("bbababaaaa") << endl;
    // 6

    return 0;
}