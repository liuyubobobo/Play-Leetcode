/// Source : https://leetcode.com/problems/swap-for-maximum-repeated-substring/
/// Author : liuyubobobo
/// Time   : 2019-08-10

#include <iostream>
#include <vector>

using namespace std;


/// Presum
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int maxRepOpt1(string text) {

        int n = text.size();
        vector<vector<int>> occurs(26, vector<int>(n + 1, 0));
        for(int i = 0; i < n; i ++)
            for(char c = 'a'; c <= 'z'; c ++)
                occurs[c - 'a'][i + 1] = occurs[c - 'a'][i] + (text[i] == c);

        vector<int> split;
        for(int start = 0, i = start + 1; i <= n; i ++)
            if(i == n || text[i] != text[start]){
                split.push_back(i - start);
                start = i;
                i = start;
            }
//        for(int e: split) cout << e << " "; cout << endl;

        vector<int> presum = {0};
        for(int e: split) presum.push_back(presum.back() + e);

        int res = *max_element(split.begin(), split.end());
        for(int i = 2; i < split.size(); i ++)
            if(text[presum[i - 2 + 1] - 1] == text[presum[i + 1] - 1] && split[i - 1] == 1){
                int c = text[presum[i - 2 + 1] - 1] - 'a';
                if(occurs[c][n] - occurs[c][presum[i + 1]] || occurs[c][presum[i - 2]])
                    res = max(res, split[i - 2] + split[i - 1] + split[i]);
                else
                    res = max(res, split[i - 2] + split[i]);
            }

        for(int i = 0; i < split.size(); i ++){
            int c = text[presum[i + 1] - 1] - 'a';
            if(occurs[c][presum[i]]) res = max(res, split[i] + 1);
            if(occurs[c][n] - occurs[c][presum[i + 1]]) res = max(res, split[i] + 1);
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