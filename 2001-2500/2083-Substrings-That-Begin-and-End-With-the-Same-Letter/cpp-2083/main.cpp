/// Source : https://leetcode.com/problems/substrings-that-begin-and-end-with-the-same-letter/
/// Author : liuyubobobo
/// Time   : 2021-11-27

#include <iostream>
#include <vector>

using namespace std;


/// Linear Scan
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    long long numberOfSubstrings(string s) {

        vector<int> f(26, 0);
        long long res = 0;
        for(int i = 0; i < s.size(); i ++){
            f[s[i] - 'a'] ++;
            res += f[s[i] - 'a'];
        }
        return res;
    }
};


int main() {

    return 0;
}
