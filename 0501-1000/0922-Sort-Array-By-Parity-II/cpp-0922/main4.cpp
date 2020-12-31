/// Source : https://leetcode.com/problems/sort-array-by-parity-ii/description/
/// Author : liuyubobobo
/// Time   : 2018-10-14

#include <iostream>
#include <vector>

using namespace std;


/// Make the change in place
/// and the code clearer :-)
///
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {

        int j = 1;
        for(int i = 0; i < A.size(); i += 2)
            if(A[i] % 2){
                for(; j < A.size(); j += 2)
                    if(A[j] % 2 == 0)
                        break;
                swap(A[i], A[j]);
            }
        return A;
    }
};


int main() {

    return 0;
}