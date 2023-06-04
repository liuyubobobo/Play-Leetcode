/// Source : https://leetcode.com/problems/sum-of-matrix-after-queries/description/
/// Author : liuyubobobo
/// Time   : 2023-06-04

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(|queries|)
/// Space Complexity: O(n)
class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {

        long long res = 0;

        vector<bool> row_visited(n, false), col_visited(n, false);
        int row_left = n, col_left = n;

        for(int i = queries.size() - 1; i >= 0; i --){
            int type = queries[i][0], index = queries[i][1], val = queries[i][2];

            if(type == 0){
                if(row_visited[index]) continue;

                res += (long long)val * col_left;
                row_visited[index] = true;
                row_left --;
            }
            else{
                if(col_visited[index]) continue;

                res += (long long)val * row_left;
                col_visited[index] = true;
                col_left --;
            }
        }
        return res;
    }
};


int main() {

    return 0;
}
