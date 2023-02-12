/// Source : https://leetcode.com/problems/subsequence-with-the-minimum-score/description/
/// Author : liuyubobobo
/// Time   : 2023-02-12

#include <iostream>
#include <vector>

using namespace std;


/// Pre and Suf
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int minimumScore(string s, string t) {

        int sn = s.size(), tn = t.size();

        vector<int> pre(sn, 0), suf(sn, 0);
        for(int i = 0, j = 0; i < sn; i ++){
            if(j < tn && s[i] == t[j]) pre[i] = ++j;
            else if(i > 0) pre[i] = pre[i - 1];
        }
        for(int i = sn - 1, j = tn - 1; i >= 0; i --){
            if(j >= 0 && s[i] == t[j]) suf[i] = tn - (j --);
            else if(i + 1 < sn) suf[i] = suf[i + 1];
        }

        int res = min(tn - suf[0], tn - pre.back());
        for(int i = 0; i + 1 < sn; i ++)
            res = min(res, tn - pre[i] - suf[i + 1]);
        return max(res, 0);
    }
};


int main() {

    return 0;
}
