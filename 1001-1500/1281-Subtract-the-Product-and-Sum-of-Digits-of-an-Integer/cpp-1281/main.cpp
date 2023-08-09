/// Source : https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/description/
/// Author : liuyubobobo
/// Time   : 2023-08-08

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(logn)
/// Space Complexity: O(1)
class Solution {
public:
    int subtractProductAndSum(int n) {
        return product(n) - sum(n);
    }

private:
    int product(int x){
        int res = 1;
        while(x)
            res *= x % 10, x /= 10;
        return res;
    }

    int sum(int x){
        int res = 0;
        while(x)
            res += x % 10, x /= 10;
        return res;
    }
};


int main() {

    return 0;
}
