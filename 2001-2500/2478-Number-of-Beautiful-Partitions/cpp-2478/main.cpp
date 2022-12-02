/// Source : https://leetcode.com/problems/number-of-beautiful-partitions/description/
/// Author : liuyubobobo
/// Time   : 2022-12-01

#include <iostream>
#include <vector>

using namespace std;


/// DP
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {

private:
    const long long MOD = 1e9 + 7;

public:
    int beautifulPartitions(string s, int k, int minLength) {

        int n = s.size();

        vector<long long> dp(n, 0), sufsum(n, 0);
        for(int i = n - minLength; i >= 0; i --)
            if(can_be_start(s, i) && !is_prime(s[n - 1])) dp[i] = 1;

        sufsum[n - 1] = dp[n - 1];
        for(int i = n - 2; i >= 0; i --) sufsum[i] = dp[i] + sufsum[i + 1];

        for(int cnt = 2; cnt <= k; cnt ++){
            vector<long long> tdp(n, 0);
            for(int i = n - cnt * minLength; i >= 0; i --){
                if(can_be_start(s, i)) tdp[i] = sufsum[i + minLength];
            }

            sufsum[n - 1]= tdp[n - 1];
            for(int i = n - 2; i >= 0; i --)
                sufsum[i] = (tdp[i] + sufsum[i + 1]) % MOD;
            dp = tdp;
        }
        return dp[0];
    }

private:
    bool can_be_start(const string& s, int index){
        return is_prime(s[index]) && (index == 0 || !is_prime(s[index - 1]));
    }

    bool is_prime(char c){
        return c == '2' || c == '3' || c == '5' || c == '7';
    }
};


int main() {

    string s1 = "23542185131";
    cout << Solution().beautifulPartitions(s1, 3, 2) << '\n';
    // 3

    string s2 = "23542185131";
    cout << Solution().beautifulPartitions(s2, 3, 3) << '\n';
    // 1

    string s3 = "3312958";
    cout << Solution().beautifulPartitions(s3, 3, 1) << '\n';
    // 1

    return 0;
}
