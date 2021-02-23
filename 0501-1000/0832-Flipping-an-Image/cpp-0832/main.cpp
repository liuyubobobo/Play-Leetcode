/// Source : https://leetcode.com/problems/flipping-an-image/
/// Author : liuyubobobo
/// Time   : 2021-02-23

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(R * C)
/// Space Complexity: O(1)
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {

        int R = A.size();
        if(R == 0) return A;

        int C = A[0].size();
        if(C == 0) return A;

        for(int i = 0; i < R; i ++){

            int l = 0, r = C - 1;
            while(l < r) swap(A[i][l ++], A[i][r --]);

            for(int& e: A[i]) e = !e;
        }
        return A;
    }
};


int main() {

    return 0;
}
