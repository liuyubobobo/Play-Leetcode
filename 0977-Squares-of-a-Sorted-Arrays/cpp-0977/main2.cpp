/// Source : https://leetcode.com/problems/squares-of-a-sorted-array/
/// Author : liuyubobobo
/// Time   : 2019-01-20

#include <iostream>
#include <vector>

using namespace std;


/// Two Pointers
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {

        int n = A.size(), i = 0, j = n -1;
        vector<int> ret;
        while(i <= j)
            if(abs(A[i]) > abs(A[j]))
                ret.push_back(A[i] * A[i]), i ++;
            else
                ret.push_back(A[j] * A[j]), j --;
        reverse(ret.begin(), ret.end());
        return ret;
    }
};


int main() {

    return 0;
}