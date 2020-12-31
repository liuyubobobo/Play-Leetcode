/// Source : https://leetcode.com/problems/count-primes/submissions/
/// Author : liuyubobobo
/// Time   : 2020-12-02

#include <iostream>
#include <vector>

using namespace std;


/// Shieve Prime
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    int countPrimes(int n) {

        int res = 0;
        vector<int> shieve(n, false);
        for(int i = 2; i < n; i ++)
            if(!shieve[i]){
                res ++;
                for(int j = i; j < n; j += i) shieve[j] = true;
            }
        return res;
    }
};


int main() {

    return 0;
}
