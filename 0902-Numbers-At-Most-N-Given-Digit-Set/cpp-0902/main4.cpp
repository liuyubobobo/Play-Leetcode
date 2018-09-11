/// Source : https://leetcode.com/problems/numbers-at-most-n-given-digit-set/description/
/// Author : liuyubobobo
/// Time   : 2018-09-11

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


/// Dynamic Programming
/// Time Complexity: (logN)
/// Space Complexity: O(logN)
class Solution {

public:
    int atMostNGivenDigitSet(vector<string>& D, int N) {

        string dset = "";
        for(string d: D)
            dset += d;

        string snum = to_string(N);
        int dnum = snum.size();

        // dp[i]: the number of num <= last i digits of N
        vector<int> dp(dnum + 1, 0);
        dp[0] = 1;
        for(int i = 1; i <= dnum; i ++){
            for(int j = 0; j < dset.size(); j ++)
                if(dset[j] < snum[dnum - i])
                    dp[i] += (int)pow(dset.size(), i - 1);
                else if(dset[j] == snum[dnum - i])
                    dp[i] += dp[i - 1];
                else
                    break;
        }

        int res = 0;
        for(int i = 1; i < dnum; i ++)
            res += (int)pow(dset.size(), i);
        return res + dp[dnum];
    }
};


int main() {

    vector<string> D1 = {"1","3","5","7"};
    cout << Solution().atMostNGivenDigitSet(D1, 100) << endl;
    // 20

    vector<string> D2 = {"1", "4", "9"};
    cout << Solution().atMostNGivenDigitSet(D2, 1000000000) << endl;
    // 29523

    vector<string> D3 = {"3", "4", "8"};
    cout << Solution().atMostNGivenDigitSet(D3, 4) << endl;
    // 2

    vector<string> D4 = {"1", "2", "3", "6", "7", "8"};
    cout << Solution().atMostNGivenDigitSet(D4, 211) << endl;
    // 79

    vector<string> D5 = {"1", "5", "7", "8"};
    cout << Solution().atMostNGivenDigitSet(D5, 10212) << endl;
    // 340

    return 0;
}