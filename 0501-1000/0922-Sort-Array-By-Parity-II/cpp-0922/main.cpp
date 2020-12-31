/// Source : https://leetcode.com/problems/sort-array-by-parity-ii/description/
/// Author : liuyubobobo
/// Time   : 2018-10-13

#include <iostream>
#include <vector>

using namespace std;


/// Seperate odd and even elements into different vectors
/// Time Complexity: O(n)
/// Space Complexity: O(2*n)
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {

        vector<int> even, odd;
        for(int i = 0; i < A.size(); i ++)
            if(A[i] % 2)
                odd.push_back(A[i]);
            else
                even.push_back(A[i]);

        vector<int> ret;
        int p_odd = 0, p_even = 0;
        for(int i = 0; i < A.size(); i ++)
            if(i % 2)
                ret.push_back(odd[p_odd ++]);
            else
                ret.push_back(even[p_even ++]);
        return ret;
    }
};


int main() {

    return 0;
}