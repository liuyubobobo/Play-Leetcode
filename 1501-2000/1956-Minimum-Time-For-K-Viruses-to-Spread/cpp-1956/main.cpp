/// Source : https://leetcode.com/problems/minimum-time-for-k-viruses-to-spread/
/// Author : liuyubobobo
/// Time   : 2021-07-02

#include <iostream>
#include <vector>

using namespace std;


/// State Compression + Brute Force
/// Time Complexity: O(n^2 + 2^n * k^2)
/// Space Complexity: O(n^2)
class Solution {
public:
    int minDayskVariants(vector<vector<int>>& points, int k) {

        int n = points.size();
        vector<vector<int>> A(n, vector<int>(n, 0));
        for(int i = 0; i < n; i ++)
            for(int j = i + 1; j < n; j ++){
                int d = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                A[i][j] = A[j][i] = (d + 1) / 2;
            }

        int res = INT_MAX;
        for(int state = 1; state <= (1 << n); state ++)
            if(__builtin_popcount(state) == k){

                vector<int> v(k);
                int index = 0;
                for(int j = 0; j < n; j ++)
                    if(state & (1 << j)) v[index ++] = j;

                int tres = INT_MIN;
                for(int i = 0; i < k; i ++)
                    for(int j = i + 1; j < k; j ++)
                        tres = max(tres, A[v[i]][v[j]]);
                res = min(res, tres);
            }
        return res;
    }
};


int main() {

    return 0;
}
