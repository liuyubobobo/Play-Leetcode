#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


/// Digit DP
/// Time Complexity: O(logn)
/// Space Complexity: O(logn)
class Solution {
public:
    int countDigitOne(int n) {

        if(!n) return 0;

        vector<int> digits = get_digits(n);
        vector<vector<int>> dp(digits.size(), vector<int>(2, -1));
        return dfs(0, 1, digits, dp);
    }

private:
    int dfs(int index, int limit,
            const vector<int>& digits, vector<vector<int>>& dp){

        if(index == digits.size()) return 0;
        if(dp[index][limit] != -1) return dp[index][limit];

        int bound = limit ? digits[index] : 9;
        int res = 0;
        for(int i = 0; i <= bound; i ++){
            res += dfs(index + 1, limit && i == bound, digits, dp);
            if(i == 1) res += i == bound ? get_num(digits, index + 1) + 1 : pow(10, digits.size() - index - 1);
        }
        return dp[index][limit] = res;
    }

    int get_num(const vector<int>& digits, int start){
        int res = 0;
        for(int i = start; i < digits.size(); i ++)
            res = res * 10 + digits[i];
        return res;
    }

    vector<int> get_digits(int x){
        vector<int> res;
        while(x) res.push_back(x % 10), x /= 10;
        reverse(res.begin(), res.end());
        return res;
    }
};


int main() {

    cout << Solution().countDigitOne(13) << endl;
    // 6

    cout << Solution().countDigitOne(100) << endl;
    // 21

    return 0;
}
