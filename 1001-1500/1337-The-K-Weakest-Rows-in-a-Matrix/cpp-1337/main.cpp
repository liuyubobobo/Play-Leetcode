/// Source : https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/
/// Author : liuyubobobo
/// Time   : 2020-02-01

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Sorting
/// Time Complexity: O(m * n + nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {

        vector<pair<int, int>> res;
        for(int i = 0; i < mat.size(); i ++)
            res.push_back(make_pair(accumulate(mat[i].begin(), mat[i].end(), 0), i));

        sort(res.begin(), res.end());

        vector<int> ret;
        for(int i = 0; i < k; i ++)
            ret.push_back(res[i].second);
        return ret;
    }
};


int main() {

    return 0;
}
