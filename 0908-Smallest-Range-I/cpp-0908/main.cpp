/// Source : https://leetcode.com/problems/smallest-range-i/description/
/// Author : liuyubobobo
/// Time   : 2018-09-2

#include <iostream>
#include <vector>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {

        int mina = *min_element(A.begin(), A.end());
        int maxa = *max_element(A.begin(), A.end());
        int diff = maxa - mina;
        return diff >= 2 * K ? diff - 2 * K : 0;
    }
};


int main() {

    return 0;
}