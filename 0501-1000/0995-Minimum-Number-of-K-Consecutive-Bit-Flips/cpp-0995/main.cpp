/// Source : https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/
/// Author : liuyubobobo
/// Time   : 2019-02-16

#include <iostream>
#include <vector>

using namespace std;


/// Greedy + Simulation
/// Time Complexity: O((N - K) * K)
/// Space Complexity: O(1)
class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {

        int res = 0;
        for(int i = 0; i < A.size(); i ++)
            if(A[i] == 0){
                if(i + K > A.size()) return -1;

                res ++;
                for(int j = 0; j < K; j ++)
                    A[i + j] = 1 - A[i + j];
            }
        return res;
    }
};


int main() {

    vector<int> A1 = {0,1,0};
    cout << Solution().minKBitFlips(A1, 1) << endl;
    // 2

    vector<int> A2 = {1,1,0};
    cout << Solution().minKBitFlips(A2, 2) << endl;
    // -1

    vector<int> A3 = {0,0,0,1,0,1,1,0};
    cout << Solution().minKBitFlips(A3, 3) << endl;
    // 3

    return 0;
}