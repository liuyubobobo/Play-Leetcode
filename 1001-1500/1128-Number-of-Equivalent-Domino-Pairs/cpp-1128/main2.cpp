/// Source : https://leetcode.com/problems/number-of-equivalent-domino-pairs/
/// Author : liuyubobobo
/// Time   : 2019-07-27

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


/// Sorting and split
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {

        vector<int> v;
        for(const vector<int>& d: dominoes)
            v.push_back(min(d[0], d[1]) * 10 + max(d[0], d[1]));

        sort(v.begin(), v.end());
        int res = 0;
        for(int start = 0, i = 1; i <= v.size(); i ++)
            if(i == v.size() || v[i] != v[start]){
                int f = i - start;
                res += f * (f - 1) / 2;
                start = i;
                i = start;
            }
        return res;
    }
};


int main() {

    vector<vector<int>> v = {{1,2},{1,2},{1,1},{1,2},{2,2}};
    cout << Solution().numEquivDominoPairs(v) << endl;

    return 0;
}