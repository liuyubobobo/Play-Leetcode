/// Source : https://leetcode.com/problems/maximum-matrix-sum/
/// Author : liuyubobobo
/// Time   : 2021-08-21

#include <iostream>
#include <vector>

using namespace std;


/// Greedy
/// Time Complexity: O(n^2 * log(n^2))
/// Space Complexity: O(n^2)
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {

        int neg = 0;
        vector<long long> v;
        for(const vector<int>& row: matrix){
            for(int e: row){
                neg += (e < 0);
                v.push_back(abs(e));
            }
        }

        sort(v.begin(), v.end());
        if(neg & 1) v[0] = -v[0];

        long long res = 0ll;
        for(long long e: v) res += e;
        return res;
    }
};


int main() {

    return 0;
}
