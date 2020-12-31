/// Source : https://leetcode.com/problems/divisor-game/
/// Author : liuyubobobo
/// Time   : 2019-04-13

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {

public:
    bool divisorGame(int N) {

        vector<int> dp(N + 1, -1);
        return dfs(N, dp, true);
    }

private:
    bool dfs(int x, vector<int>& dp, bool isAlice){

        if(x == 1) return isAlice ? false : true;

        if(dp[x] != -1) return dp[x];

        if(isAlice){
            for(int i = 1; i * i <= x; i ++)
                if(x % i == 0 && dfs(x - i, dp, false))
                    return dp[x] = true;
            return dp[x] = false;
        }
        else{
            for(int i = 1; i * i <= x; i ++)
                if(x % i == 0 && !dfs(x - i, dp, true))
                    return dp[x] = false;
            return dp[x] = true;
        }
    }
};


int main() {

    cout << Solution().divisorGame(2) << endl; // true
    cout << Solution().divisorGame(3) << endl; // false
    cout << Solution().divisorGame(9) << endl; // false

    return 0;
}