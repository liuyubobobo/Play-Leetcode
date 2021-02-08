/// Source : https://leetcode.com/problems/longest-turbulent-subarray/
/// Author : liuyubobobo
/// Time   : 2018-01-19
/// Updated: 2021-02-08

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
        int res = 0;
        for(int i = 1; i < A.size(); i ++){
            diff.push_back(get_sign(A[i] - A[i - 1]));
            if(diff.back() != 0) res = 1;
        }

        for(int start = 0, i = start + 1; i < diff.size(); )
            if((diff[i - 1] == 1 && diff[i] == -1) || (diff[i - 1] == -1 && diff[i] == 1)){
                res = max(res, i + 1 - start);
                i ++;
            }
            else start = i, i = start + 1;
        return res + 1;
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

    vector<int> A4 = {9, 9};
    cout << Solution().maxTurbulenceSize(A4) << endl;
    // 1

    vector<int> A5 = {9, 9, 9};
    cout << Solution().maxTurbulenceSize(A5) << endl;
    // 1

    return 0;
}