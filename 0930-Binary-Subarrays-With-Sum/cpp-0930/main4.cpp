/// Source : https://leetcode.com/problems/binary-subarrays-with-sum/
/// Author : liuyubobobo
/// Time   : 2018-10-29

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Three Pointers
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {

        int i_low = 0, i_high = 0;
        int sum_low = 0, sum_high = 0;
        int res = 0;
        for(int j = 0; j < A.size(); j ++){
            sum_low += A[j];
            while(sum_low > S)
                sum_low -= A[i_low ++];

            sum_high += A[j];
            while((sum_high > S || (sum_high == S && A[i_high] == 0)) && i_high < j)
                sum_high -= A[i_high ++];

            if(sum_low == S)
                res += (i_high - i_low + 1);
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