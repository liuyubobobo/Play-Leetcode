/// Source : https://leetcode.com/problems/flip-string-to-monotone-increasing/
/// Author : liuyubobobo
/// Time   : 2018-10-20

#include <iostream>
#include <vector>

using namespace std;


/// Precalculation
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int minFlipsMonoIncr(string S) {

        if(S.size() == 0 || S.size() == 1)
            return 0;

        int n = S.size();
        vector<int> zeros(n + 1, 0), ones(n + 1, 0);

        for(int i = 1; i <= S.size(); i ++)
            ones[i] = ones[i - 1] + (S[i - 1] == '1');

        for(int i = n - 1; i >= 0; i --)
            zeros[i] = zeros[i + 1] + (S[i] == '0');

        int res = INT_MAX;
        for(int i = 0; i <= n; i ++)
            res = min(res, ones[i] + zeros[i]);
        return res;
    }
};


int main() {

    return 0;
}