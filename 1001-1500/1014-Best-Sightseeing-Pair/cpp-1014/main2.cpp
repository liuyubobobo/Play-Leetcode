/// Source : https://leetcode.com/problems/best-sightseeing-pair/
/// Author : liuyubobobo
/// Time   : 2019-03-23

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {

        int n = A.size();

        int res = A[0] + A[n - 1] - (n - 1), maxv = A[n - 1] - (n - 1);
        for(int i = n - 2; i >= 0; i --){
            res = max(res, A[i] + i + maxv);
            maxv = max(maxv, A[i] - i);
        }
        return res;
    }
};


int main() {

    vector<int> A1 = {8,1,5,2,6};
    cout << Solution().maxScoreSightseeingPair(A1) << endl;
    // 11

    vector<int> A2 = {3,7,2,3};
    cout << Solution().maxScoreSightseeingPair(A2) << endl;
    // 9

    vector<int> A3 = {1, 3, 5};
    cout << Solution().maxScoreSightseeingPair(A3) << endl;
    // 7

    return 0;
}