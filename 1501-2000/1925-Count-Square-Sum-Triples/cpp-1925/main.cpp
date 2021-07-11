/// Source : https://leetcode.com/problems/count-square-sum-triples/
/// Author : liuyubobobo
/// Time   : 2021-07-11

#include <iostream>

using namespace std;


/// Brute Force
/// Time Complexity: O(n^2)
/// Space Complexity: O(1)
class Solution {
public:
    int countTriples(int n) {

        int res = 0;
        for(int i = 1; i <= n; i ++)
            for(int j = i; j <= n; j ++){
                int c = i * i + j * j;
                int cc = sqrt((double)c);
                if(cc * cc == c && 1 <= cc && cc <= n)
                    res += (i == j ? 1 : 2);
            }
        return res;
    }
};


int main() {

    return 0;
}
