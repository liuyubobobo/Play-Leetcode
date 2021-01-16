/// Source : https://leetcode.com/problems/binary-trees-with-factors/
/// Author : liuyubobobo
/// Time   : 2021-01-16

#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& A) {

        const long long MOD = 1e9 + 7;

        sort(A.begin(), A.end());
        unordered_map<int, int> map;
        for(int i = 0; i < A.size(); i ++) map[A[i]] = i;

        vector<int> dp(A.size(), 1);
        for(int i = 1; i < A.size(); i ++){
            long long res = 1ll;
            for(int j = 0; j < i; j ++)
                if(A[i] % A[j] == 0 && map.count(A[i] / A[j]))
                    res = (res + (long long)dp[j] * dp[map[A[i] / A[j]]]) % MOD;
            dp[i] = res;
        }

        return accumulate(dp.begin(), dp.end(), 0ll) % MOD;
    }
};


int main() {

    vector<int> arr1 = {2, 4};
    cout << Solution().numFactoredBinaryTrees(arr1) << endl;
    // 3

    vector<int> arr2 = {2, 4, 5, 10};
    cout << Solution().numFactoredBinaryTrees(arr2) << endl;
    // 7

    vector<int> arr3 = {15, 13, 22, 7, 11};
    cout << Solution().numFactoredBinaryTrees(arr3) << endl;
    // 5

    vector<int> arr4 = {2, 3, 6, 18};
    cout << Solution().numFactoredBinaryTrees(arr4) << endl;
    // 12

    return 0;
}
