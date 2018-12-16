/// Source : https://leetcode.com/problems/delete-columns-to-make-sorted-iii/
/// Author : liuyubobobo
/// Time   : 2018-12-16

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(m * n * n)
/// Space Complexity: O(n)
class Solution {

public:
    int minDeletionSize(vector<string>& A) {

        int m = A.size(), n = A[0].size();
        vector<int> dp(n, 1);

        for(int index = 1; index < n; index ++){

            for(int prev = index - 1; prev >= 0; prev --){

                bool ok = true;
                for(int i = 0; i < m; i ++)
                    if(A[i][index] < A[i][prev]){
                        ok = false;
                        break;
                    }
                if(ok)
                    dp[index] = max(dp[index], 1 + dp[prev]);
            }
        }

        return n - *max_element(dp.begin(), dp.end());
    }
};


int main() {

    vector<string> A1 = {"babca","bbazb"};
    cout << Solution().minDeletionSize(A1) << endl;

    return 0;
}