/// Source : https://leetcode.com/problems/largest-perimeter-triangle/
/// Author : liuyubobobo
/// Time   : 2019-01-12

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Sort and Brute Force
/// Time Complexity: O(n^2)
/// Space Complexity: O(1)
class Solution {
public:
    int largestPerimeter(vector<int>& A) {

        sort(A.begin(), A.end());

        int n = A.size();
        int best = 0;
        for(int i = n - 1; i >= 0; i --)
            for(int j = i - 1; j >= 0; j --){
                if(j - 1 >= 0 && A[j - 1] > A[i] - A[j])
                    best = max(best, A[i] + A[j] + A[j - 1]);
                else
                    break;
            }
        return best;
    }
};


int main() {

    vector<int> A1 = {2, 3, 3, 4};
    cout << Solution().largestPerimeter(A1) << endl;
    // 10

    vector<int> A2 = {2, 3, 3, 6};
    cout << Solution().largestPerimeter(A2) << endl;
    // 8

    return 0;
}