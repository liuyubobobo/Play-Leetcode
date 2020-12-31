/// Source : https://leetcode.com/problems/sort-array-by-parity/solution/
/// Author : liuyubobobo
/// Time   : 2018-09-15

#include <iostream>
#include <vector>

using namespace std;


/// Sorting by custom comparator
/// Time Complexity : O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {

        sort(A.begin(), A.end(), cmp);
        return A;
    }

private:
    static bool cmp(int a, int b){
        if(a % 2 != b % 2)
            return a % 2 == 0;
        else
            return a < b;
    }
};


int main() {

    return 0;
}