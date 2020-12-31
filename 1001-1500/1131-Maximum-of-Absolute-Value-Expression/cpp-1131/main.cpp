/// Source : https://leetcode.com/problems/maximum-of-absolute-value-expression/
/// Author : liuyubobobo
/// Time   : 2019-08-25

#include <iostream>
#include <vector>

using namespace std;


/// Mathematics
/// |a - b| = max(a - b, b - a)
/// Time Compelxity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {

        int n = arr1.size(), res = INT_MIN;
        for(int a = -1; a <= 1; a += 2)
            for(int b = -1; b <= 1; b += 2)
                for(int c = -1; c <= 1; c += 2){

                    int maxv = INT_MIN, minv = INT_MAX;
                    for(int i = 0; i < n; i ++){
                        int x = a * arr1[i] + b * arr2[i] + c * i;
                        maxv = max(maxv, x);
                        minv = min(minv, x);
                    }
                    res = max(res, maxv - minv);
                }
        return res;
    }
};


int main() {

    vector<int> arr1 = {1, 2, 3, 4}, arr2 = {-1, 4, 5, 6};
    cout << Solution().maxAbsValExpr(arr1, arr2) << endl;
    return 0;
}