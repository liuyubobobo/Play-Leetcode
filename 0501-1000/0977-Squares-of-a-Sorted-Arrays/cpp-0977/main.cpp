/// Source : https://leetcode.com/problems/squares-of-a-sorted-array/
/// Author : liuyubobobo
/// Time   : 2019-01-19

#include <iostream>
#include <vector>

using namespace std;


/// Sorting
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {

        for(int& e: A)
            e = e * e;
        sort(A.begin(), A.end());
        return A;
    }
};


int main() {

    return 0;
}