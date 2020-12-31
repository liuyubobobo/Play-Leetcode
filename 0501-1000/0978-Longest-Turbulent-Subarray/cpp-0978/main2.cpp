/// Source : https://leetcode.com/problems/longest-turbulent-subarray/
/// Author : liuyubobobo
/// Time   : 2018-01-20

#include <iostream>
#include <vector>

using namespace std;


/// No need to precalculate the diff array :)
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {

        int res = 1;
        for(int start = 0, i = start + 1; i < A.size(); i ++)
            if(i == A.size() - 1 || (long long)(A[i] - A[i - 1]) * (A[i + 1] - A[i]) >= 0){
                res = max(res, i - start);
                start = i;
                i = start;
            }
        return res;
    }
};


int main() {

    vector<int> A1 = {9,4,2,10,7,8,8,1,9};
    cout << Solution().maxTurbulenceSize(A1) << endl;
    // 5

    vector<int> A2 = {4,8,12,16};
    cout << Solution().maxTurbulenceSize(A2) << endl;
    // 2

    vector<int> A3 = {100};
    cout << Solution().maxTurbulenceSize(A3) << endl;
    // 1

    return 0;
}