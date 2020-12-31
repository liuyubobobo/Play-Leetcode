/// Source : https://leetcode.com/problems/xor-queries-of-a-subarray/
/// Author : liuyubobobo
/// Time   : 2020-01-04

#include <iostream>
#include <vector>

using namespace std;


/// Pre Sum
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {

        vector<int> sum = {0, arr[0]};
        for(int i = 1; i < arr.size(); i ++)
            sum.push_back(sum.back() ^ arr[i]);

        vector<int> res;
        for(const vector<int>& q: queries)
            res.push_back(sum[q[1] + 1] ^ sum[q[0]]);
        return res;
    }
};


int main() {
    
    return 0;
}
