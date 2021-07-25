/// Source : https://leetcode.com/problems/longest-common-subsequence-between-sorted-arrays/
/// Author : liuyubobobo
/// Time   : 2021-07-02

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n * m)
/// Space Complexity: O(m)
class Solution {
public:
    vector<int> longestCommomSubsequence(vector<vector<int>>& arrays) {

        vector<int> res = arrays[0];
        for(int i = 1; i < arrays.size(); i ++)
            res = get_lcs(res, arrays[i]);
        return res;
    }

private:
    vector<int> get_lcs(const vector<int>& a, const vector<int>& b){

        vector<int> res;
        int i = 0, j = 0;
        while(i < a.size() && j < b.size())
            if(a[i] == b[j]) res.push_back(a[i]), i ++, j ++;
            else if(a[i] < b[j]) i ++;
            else j ++;
        return res;
    }
};


int main() {

    return 0;
}
