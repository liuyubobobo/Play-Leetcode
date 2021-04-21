/// Source : https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/
/// Author : liuyubobobo
/// Time   : 2021-04-21

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Using TreeSet
/// Time Complexity: O(n^3*logn)
/// Space Complexity: O(n^2)
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {

        int R = matrix.size(), C = matrix[0].size();
        vector<vector<int>> presum(R + 1, vector<int>(C, 0));
        for(int j = 0; j < C; j ++)
            for(int i = 0; i < R; i ++)
                presum[i + 1][j] = presum[i][j] + matrix[i][j];

        int res = INT_MIN;
        for(int r1 = 0; r1 < R; r1 ++)
            for(int r2 = r1; r2 < R; r2 ++){

                vector<int> v(C);
                for(int j = 0; j < C; j ++)
                    v[j] = presum[r2 + 1][j] - presum[r1][j];

                res = max(res, solve(v, k));
            }
        return res;
    }

private:
    int solve(const vector<int>& v, int k){

        set<int> seen;
        seen.insert(0);

        int sum = 0, res = INT_MIN;
        for(int e: v){

            sum += e;
            set<int>::iterator iter = seen.lower_bound(sum - k);
            if(iter != seen.end())
                res = max(res, sum - *iter);
            seen.insert(sum);
        }
        return res;
    }
};


int main() {

    vector<vector<int>> matrix1 = {{2, 2, -1}};
    cout << Solution().maxSumSubmatrix(matrix1, 0) << endl;
    // -1

    return 0;
}
