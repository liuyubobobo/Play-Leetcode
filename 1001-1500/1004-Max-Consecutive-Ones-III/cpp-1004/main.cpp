/// Source : https://leetcode.com/problems/max-consecutive-ones-iii/
/// Author : liuyubobobo
/// Time   : 2019-03-02

#include <iostream>
#include <vector>

using namespace std;


/// Sliding Window
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {

        int i = 0, j = -1, curK = 0, curLen = 0, best = 0;
        while(j + 1 < A.size()){
            if(A[j + 1] == 1)
                curLen += 1,
                j ++;
            else{
                // data[j + 1].first == 0
                if(curK < K)
                    curLen += 1,
                    curK += 1,
                    j ++;
                else
                    curLen -= 1,
                    curK -= (A[i] == 0 ? 1 : 0),
                    i ++;
            }
            best = max(best, curLen);
        }
        return best;
    }
};


int main() {

    vector<int> A1 = {1,1,1,0,0,0,1,1,1,1,0};
    cout << Solution().longestOnes(A1, 2) << endl;
    // 6

    vector<int> A2 = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    cout << Solution().longestOnes(A2, 3) << endl;
    // 10

    vector<int> A3 = {1,0,0,0,1,1,0,0,1,1,0,0,0,0,0,0,1,1,1,1,0,1,0,1,1,1,1,1,1,0,1,0,1,0,0,1,1,0,1,1};
    cout << Solution().longestOnes(A3, 8) << endl;
    // 25

    return 0;
}