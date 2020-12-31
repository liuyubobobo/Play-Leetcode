/// Source : https://leetcode.com/problems/triples-with-bitwise-and-equal-to-zero/
/// Author : liuyubobobo
/// Time   : 2019-01-26

#include <iostream>
#include <vector>

using namespace std;


/// Using HashSet
/// Time Complexity: O(max(2^16 * n, n^2))
/// Space Complexity: O(2^16 * n)
class Solution {
public:
    int countTriplets(vector<int>& A) {

        int n = A.size();
        vector<int> table(65536, 0);
        for(int a: A)
            for(int i = 0; i < 65536; i ++)
                if(!(a & i))
                    table[i] ++;

        int res = 0;
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < n; j ++)
                res += table[A[i] & A[j]];
        return res;
    }
};


int main() {

    return 0;
}