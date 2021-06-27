/// Source : https://leetcode.com/problems/number-of-wonderful-substrings/
/// Author : liuyubobobo
/// Time   : 2021-06-26

#include <iostream>
#include <vector>

using namespace std;


/// State Compression + Using HashMap
/// Time Complexity: O(n)
/// Space Complexity: O(2^10)
class Solution {

private:
    const int W = 10;

public:
    long long wonderfulSubstrings(string word) {

        int n = word.size();

        vector<int> table(1 << 10, 0);
        table[0] = 1;

        int state = 0;
        long long res = 0ll;
        for(int i = 0; i < n; i ++){
            int w = word[i] - 'a';
            state ^= (1 << w);

            res += table[state];

            for(int k = 0; k < W; k ++)
                res += table[state ^ (1 << k)];

            table[state] ++;
        }
        return res;
    }
};


int main() {

    cout << Solution().wonderfulSubstrings("aba") << endl;
    // 4

    cout << Solution().wonderfulSubstrings("aabb") << endl;
    // 9

    cout << Solution().wonderfulSubstrings("he") << endl;
    // 2

    return 0;
}
