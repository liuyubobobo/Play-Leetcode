/// Source : https://leetcode.com/problems/integer-break/description/
/// Author : liuyubobobo
/// Time   : 2017-11-19

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/// Memory Search
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
private:
    vector<int> memo;

    int max3(int a, int b, int c){
        return max(a, max(b, c));
    }

    int breakInteger(int n){

        if(n == 1)
            return 1;

        if(memo[n] != -1)
            return memo[n];

        int res = -1;
        for(int i = 1 ; i <= n - 1 ; i ++)
            res = max3(res, i * (n - i) , i * breakInteger(n - i));
        memo[n] = res;
        return res;
    }

public:
    int integerBreak(int n) {
        assert(n >= 1);
        memo.clear();
        for(int i = 0 ; i < n + 1 ; i ++)
            memo.push_back(-1);
        return breakInteger(n);
    }
};

int main() {

    cout << Solution().integerBreak(2) << endl;
    cout << Solution().integerBreak(10) << endl;

    return 0;
}