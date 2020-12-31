/// Source : https://leetcode.com/problems/partition-array-into-disjoint-intervals/description/
/// Author : liuyubobobo
/// Time   : 2018-09-29

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/// pre-calculation
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int partitionDisjoint(vector<int>& A) {

        int n = A.size();

        vector<int> lmax(n, A[0]);
        for(int i = 1; i < n; i ++)
            lmax[i] = max(lmax[i - 1], A[i]);

        vector<int> rmin(n, A[n - 1]);
        for(int i = n - 2; i >= 0; i --)
            rmin[i] = min(rmin[i + 1], A[i]);

        for(int i = 1; i < n; i ++)
            if(lmax[i - 1] <= rmin[i])
                return i;

        assert(false);
        return 0;
    }
};


int main() {

    vector<int> A1 = {5,0,3,8,6};
    cout << Solution().partitionDisjoint(A1) << endl;
    // 3

    vector<int> A2 = {1,1,1,0,6,12};
    cout << Solution().partitionDisjoint(A2) << endl;
    // 4

    vector<int> A3 = {32,57,24,19,0,24,49,67,87,87};
    cout << Solution().partitionDisjoint(A3) << endl;
    // 7

    vector<int> A4 = {1, 1};
    cout << Solution().partitionDisjoint(A4) << endl;
    // 1

    return 0;
}