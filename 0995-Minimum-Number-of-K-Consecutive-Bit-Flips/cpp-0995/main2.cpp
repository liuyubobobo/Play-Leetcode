/// Source : https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/
/// Author : liuyubobobo
/// Time   : 2019-02-18

#include <iostream>
#include <vector>

using namespace std;


/// Greedy + Events
/// Record every closed event
/// Time Complexity: O(N)
/// Space Complexity: O(N)
class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {

        int res = 0;
        vector<bool> event(A.size(), false);
        int flip = 0;

        for(int i = 0; i < A.size(); i ++){
            if((A[i] && flip % 2) || (!A[i] && flip % 2 == 0)){

                if(i + K - 1 >= A.size()) return -1;

                res ++;

                flip ++;
                event[i + K - 1] = true;
            }

            if(event[i]) flip --;
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