/// Source : https://leetcode.com/problems/binary-subarrays-with-sum/
/// Author : liuyubobobo
/// Time   : 2018-10-29

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Using PreSum and HashMap
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {

        if(A.size() == 0)
            return S == 0;

        vector<int> sum(A.size() + 1, 0);
        for(int i = 0; i < A.size(); i ++)
            sum[i + 1] = A[i] + sum[i];

        unordered_map<int, int> freq; // sum, freq
        freq[0] ++;

        int res = 0;
        for(int i = 0; i < A.size(); i ++){
            res += freq[sum[i + 1] - S];
            freq[sum[i + 1]] ++;
        }
        return res;
    }
};


int main() {

    vector<int> A1 = {1,0,1,0,1};
    cout << Solution().numSubarraysWithSum(A1, 2) << endl;
    // 4

    vector<int> A2 = {0,0,0,0,0};
    cout << Solution().numSubarraysWithSum(A2, 0) << endl;
    // 15

    vector<int> A3 = {0,0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0};
    cout << Solution().numSubarraysWithSum(A3, 3) << endl;
    // 48

    return 0;
}