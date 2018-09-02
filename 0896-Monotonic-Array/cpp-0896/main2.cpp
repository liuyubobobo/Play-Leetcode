/// Source : https://leetcode.com/problems/monotonic-array/description/
/// Author : liuyubobobo
/// Time   : 2018-09-01

#include <iostream>
#include <vector>

using namespace std;


/// One Pass
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    bool isMonotonic(vector<int>& A) {

        int trend = 0;
        for(int i = 1; i < A.size() ; i ++)
            if(trend == 0){
                if(A[i] > A[i - 1]) trend = 1;
                else if(A[i] < A[i - 1]) trend = -1;
            }
            else{
                if(A[i] > A[i - 1] && trend == -1) return false;
                else if(A[i] < A[i - 1] && trend == 1) return false;
            }

        return true;
    }
};


int main() {

    return 0;
}