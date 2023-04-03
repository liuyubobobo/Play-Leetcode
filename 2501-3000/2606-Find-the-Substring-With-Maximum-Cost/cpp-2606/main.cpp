/// Source : https://leetcode.com/problems/find-the-substring-with-maximum-cost/description/
/// Author : liuyubobobo
/// Time   : 2023-04-02

#include <iostream>
#include <vector>
#include <climits>

using namespace std;


/// Linear Scan
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {

        vector<int> costs(26, 0);
        for (int i = 0; i < 26; i ++) costs[i] = i + 1;
        for(int i = 0; i < chars.size(); i ++)  costs[chars[i] - 'a'] = vals[i];

        int res = 0, min_pre = 0, pre = 0;
        for(int i = 0; i < s.size(); i ++) {
            pre += costs[s[i] - 'a'];
            min_pre = min(min_pre, pre);
            res = max(res, pre - min_pre);
        }
        return res;
    }
};


int main() {

    return 0;
}
