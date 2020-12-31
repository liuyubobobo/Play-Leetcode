/// Source : https://leetcode.com/problems/the-kth-factor-of-n/
/// Author : liuyubobobo
/// Time   : 2020-06-27

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int kthFactor(int n, int k) {

        vector<int> factors;
        for(int i = 1; i <= n; i ++)
            if(n % i == 0) factors.push_back(i);
        return k - 1 < factors.size() ? factors[k - 1] : -1;
    }
};


int main() {

    return 0;
}
