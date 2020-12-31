/// Source : https://leetcode.com/problems/minimum-increment-to-make-array-unique/
/// Author : liuyubobobo
/// Time   : 2018-11-25

#include <iostream>
#include <vector>

using namespace std;


/// Using sort and don't change the A array
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {

        if(A.size() == 0)
            return 0;

        sort(A.begin(), A.end());
        int res = 0, left = 0;
        for(int i = 1; i < A.size(); i ++)
            if(A[i] == A[i - 1]){
                left ++;
                res -= A[i];
            }
            else{
                int seg = min(left, A[i] - A[i - 1] - 1);
                res += (A[i - 1] + 1 + A[i - 1] + seg) * seg / 2;
                left -= seg;
            }

        if(left)
            res += (A.back() + 1 + A.back() + left) * left / 2;
        return res;
    }
};


int main() {

    return 0;
}