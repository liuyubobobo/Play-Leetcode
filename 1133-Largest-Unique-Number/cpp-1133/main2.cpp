/// Source : https://leetcode.com/problems/largest-unique-number/
/// Author : liuyubobobo
/// Time   : 2019-07-25

#include <iostream>
#include <vector>

using namespace std;


/// Sorting and Split
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    int largestUniqueNumber(vector<int>& A) {

        sort(A.begin(), A.end());
        int res = -1;
        for(int start = 0, i = 1; i <= A.size(); i ++)
            if(i == A.size() || A[i] != A[start]){
                if(i - start == 1) res = A[start];
                start = i;
                i = start;
            }
        return res;
    }
};


int main() {
    return 0;
}