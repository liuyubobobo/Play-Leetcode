/// Source : https://leetcode.com/problems/largest-perimeter-triangle/
/// Author : liuyubobobo
/// Time   : 2019-01-21

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Sort and Greedy
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    int largestPerimeter(vector<int>& A) {

        sort(A.begin(), A.end());
        for(int i = A.size() - 3; i >= 0; i --)
            if(A[i] + A[i + 1] > A[i + 2])
                return A[i] + A[i + 1] + A[i + 2];
        return 0;
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