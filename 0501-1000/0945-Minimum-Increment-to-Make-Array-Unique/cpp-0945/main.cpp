/// Source : https://leetcode.com/problems/minimum-increment-to-make-array-unique/
/// Author : liuyubobobo
/// Time   : 2018-11-24

#include <iostream>
#include <vector>

using namespace std;


/// Using sort and change the A array
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {

        sort(A.begin(), A.end());
        int res = 0;
        for(int i = 1; i < A.size(); i ++)
            if(A[i] == A[i - 1]){
                res += (A[i - 1] + 1 - A[i]);
                A[i] = A[i - 1] + 1;
            }
        return res;
    }
};


int main() {

    return 0;
}