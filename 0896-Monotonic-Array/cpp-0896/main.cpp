/// Source : https://leetcode.com/problems/monotonic-array/description/
/// Author : liuyubobobo
/// Time   : 2018-09-01

#include <iostream>
#include <vector>

using namespace std;


/// Two Pass
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    bool isMonotonic(vector<int>& A) {

        int i;
        for(i = 1; i < A.size() ; i ++)
            if(A[i] < A[i - 1])
                break;
        if(i == A.size())
            return true;

        for(i = 1; i < A.size() ; i ++)
            if(A[i] > A[i - 1])
                break;
        if(i == A.size())
            return true;

        return false;
    }
};


int main() {

    return 0;
}