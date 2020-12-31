/// Source : https://leetcode.com/problems/delete-columns-to-make-sorted/
/// Author : liuyubobobo
/// Time   : 2018-11-17

#include <iostream>
#include <vector>

using namespace std;


/// Greedy
/// Time Complexity: O(m * n)
/// Space Complexity: O(1)
class Solution {
public:
    int minDeletionSize(vector<string>& A) {

        int m = A.size();
        if(m == 0 || m == 1) return 0;

        int n = A[0].size();
        if(n == 0) return 0;

        int res = 0;
        for(int j = 0; j < n; j ++){

            for(int i = 1; i < m; i ++)
                if(A[i][j] < A[i - 1][j]){
                    res ++;
                    break;
                }
        }
        return res;
    }
};


int main() {

    return 0;
}