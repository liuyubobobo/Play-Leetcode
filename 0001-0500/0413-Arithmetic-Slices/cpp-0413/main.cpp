#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {

        int n = A.size();
        if(n <= 2) return 0;

        vector<int> dp(n, 0);
        dp[2] = A[2] - A[1] == A[1] - A[0];

        for(int i = 3; i < n; i ++)
            if(A[i] - A[i - 1] == A[i - 1] - A[i - 2])
                dp[i] = 1 + dp[i - 1];
        return accumulate(dp.begin(), dp.end(), 0);
    }
};


int main() {

    return 0;
}
