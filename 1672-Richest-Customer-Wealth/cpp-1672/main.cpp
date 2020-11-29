/// Source : https://leetcode.com/problems/richest-customer-wealth/
/// Author : liuyubobobo
/// Time   : 2020-11-28

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Brute Force
/// Time Complexity: O(n * m)
/// Space Complexity: O(1)
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {

        int res = 0;
        for(const vector<int>& v: accounts)
            res = max(res, accumulate(v.begin(), v.end(), 0));
        return res;
    }
};


int main() {

    return 0;
}
