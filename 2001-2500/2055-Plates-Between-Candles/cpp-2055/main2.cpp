/// Source : https://leetcode.com/problems/plates-between-candles/
/// Author : liuyubobobo
/// Time   : 2021-10-30

#include <iostream>
#include <vector>

using namespace std;


/// Binary Search
/// Time Complexity: O(nlogn + qlogn)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {

        int n = s.size();

        vector<int> bars;
        for(int i = 0; i < n; i ++)
            if(s[i] == '|') bars.push_back(i);

        vector<int> presum(n + 1, 0);
        for(int i = 0; i < n; i ++)
            presum[i + 1] = presum[i] + (s[i] == '*');

        vector<int> res(queries.size(), 0);
        vector<int>::iterator iter;
        for(int i = 0; i < queries.size(); i ++){
            int ql = queries[i][0], qr = queries[i][1], l, r;

            iter = lower_bound(bars.begin(), bars.end(), ql);
            if(iter == bars.end()) continue;
            l = *iter;

            iter = lower_bound(bars.begin(), bars.end(), qr);
            if(iter == bars.begin() && *iter > qr) continue;
            if(iter == bars.end() || *iter > qr) iter --;
            r = *iter;

            if(l <= r) res[i] = presum[r + 1] - presum[l];
        }
        return res;
    }
};


int main() {

    return 0;
}
