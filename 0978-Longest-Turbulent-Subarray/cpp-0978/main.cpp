/// Source : https://leetcode.com/problems/longest-turbulent-subarray/
/// Author : liuyubobobo
/// Time   : 2018-01-19

#include <iostream>
#include <vector>

using namespace std;


/// Precalculate the diff array
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {

        vector<int> diff;
        for(int i = 1; i < A.size(); i ++)
            diff.push_back(get_sign(A[i] - A[i - 1]));

        int res = 1;
        for(int start = 0, i = start + 1; i <= diff.size(); i ++)
            if(i == diff.size() || diff[i] * diff[i - 1] >= 0){
                res = max(res, i - start + 1);
                start = i;
                i = start;
            }
        return res;
    }

private:
    int get_sign(int x){
        return x > 0 ? 1 : (x == 0 ? 0 : -1);
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