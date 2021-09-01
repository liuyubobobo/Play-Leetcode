/// Source : https://leetcode.com/problems/number-of-unique-good-subsequences/
/// Author : liuyubobobo
/// Time   : 2021-08-31

#include <iostream>
#include <vector>

using namespace std;


/// DP
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {

private:
    const int MOD = 1e9 + 7;

public:
    int numberOfUniqueGoodSubsequences(string binary) {

        int end0 = 0, end1 = 0;
        for(char c: binary){
            if(c == '0') end0 = (end0 + end1) % MOD;
            else end1 = (end0 + end1 + 1) % MOD;
        }
        return (end0 + end1 + (binary.find('0') != string::npos)) % MOD;
    }
};


int main() {

    cout << Solution().numberOfUniqueGoodSubsequences("001") << endl;
    // 2

    cout << Solution().numberOfUniqueGoodSubsequences("11") << endl;
    // 2

    cout << Solution().numberOfUniqueGoodSubsequences("101") << endl;
    // 5

    cout << Solution().numberOfUniqueGoodSubsequences("1110001") << endl;
    // 23

    return 0;
}
