/// Source : https://leetcode-cn.com/problems/zui-xiao-tiao-yue-ci-shu/
/// Author : liuyubobobo
/// Time   : 2020-04-18

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {

public:
    int minJump(vector<int>& jump) {

        int n = jump.size();
        vector<int> dp(n, 1);
        for(int i = n - 2; i >= 0; i --){

            if(i + jump[i] < n) dp[i] = dp[i + jump[i]] + 1;

            for(int j = i + 1; j < n; j ++)
                if(1 + dp[i] <= dp[j]) dp[j] = 1 + dp[i];
                else break;
        }
        return dp[0];
    }
};


int main() {

    vector<int> jump1 = {2, 5, 1, 1, 1, 1};
    cout << Solution().minJump(jump1) << endl;
    // 3

    return 0;
}
