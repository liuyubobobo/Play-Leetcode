/// Source : https://leetcode.com/problems/number-of-equivalent-domino-pairs/
/// Author : liuyubobobo
/// Time   : 2019-07-20

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


/// Using Hash Map
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {

        unordered_map<int, int> freq;
        for(const vector<int>& d: dominoes)
            freq[min(d[0], d[1]) * 10 + max(d[0], d[1])] ++;

        int res = 0;
        for(const pair<int, int>& p: freq)
            res += p.second * (p.second - 1) / 2;
        return res;
    }
};


int main() {

    vector<vector<int>> v = {{1,2},{1,2},{1,1},{1,2},{2,2}};
    cout << Solution().numEquivDominoPairs(v) << endl;

    return 0;
}