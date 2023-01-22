/// Source : https://leetcode.com/problems/increment-submatrices-by-one/description/
/// Author : liuyubobobo
/// Time   : 2023-01-14

#include <iostream>
#include <vector>

using namespace std;


/// Diff Array
/// Time Complexity: O(|q| * n)
/// Space Complexity: O(n^2)
class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {

        vector<vector<int>> diff(n, vector<int>(n + 1, 0));
        for(const vector<int>& q: queries){
            int a = q[0], b = q[2], l = q[1], r = q[3];
            for(int i = a; i <= b; i ++)
                diff[i][l] += 1, diff[i][r + 1] -= 1;
        }

        vector<vector<int>> res(n, vector<int>(n));
        for(int i = 0; i < n; i ++){
            int presum = 0;
            for(int j = 0; j < n; j ++){
                presum += diff[i][j];
                res[i][j] = presum;
            }
        }
        return res;
    }
};


int main() {

    return 0;
}
