/// Source : https://leetcode.com/problems/n-repeated-element-in-size-2n-array/
/// Author : liuyubobobo
/// Time   : 2019-08-11

#include <iostream>
#include <vector>
#include <unordered_set>
#include <cassert>

using namespace std;


/// Sorting
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {

        sort(A.begin(), A.end());
        for(int i = 1; i < A.size(); i ++)
            if(A[i] == A[i - 1])
                return A[i];
        assert(false);
        return -1;
    }
};


int main() {

    return 0;
}