/// Source : https://leetcode.com/problems/valid-mountain-array/
/// Author : liuyubobobo
/// Time   : 2018-11-17

#include <iostream>
#include <vector>

using namespace std;


/// One Pass
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    bool validMountainArray(vector<int>& A) {

        if(A.size() < 3)
            return false;

        int i;
        for(i = 1; i < A.size(); i ++)
            if(A[i] < A[i - 1])
                break;
            else if(A[i] == A[i - 1])
                return false;

        if(i == 1 || i == A.size())
            return false;

        for(int j = i; j < A.size(); j ++)
            if(A[j - 1] <= A[j])
                return false;

        return true;
    }
};


int main() {

    vector<int> A1 = {0, 3, 2, 1};
    cout << Solution().validMountainArray(A1) << endl;
    // true

    return 0;
}