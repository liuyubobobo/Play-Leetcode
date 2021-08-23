/// Source : https://leetcode.com/problems/find-greatest-common-divisor-of-array/
/// Author : liuyubobobo
/// Time   : 2021-08-21

#include <iostream>
#include <vector>

using namespace std;


/// GCD
/// Time Complexity: O(nlogn)
/// Space Complexity: O(logn)
class Solution {
public:
    int findGCD(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        return gcd(nums[0], nums.back());
    }

private:
    int gcd(int a, int b)
    {
        if (a == 0) return b;
        return gcd(b % a, a);
    }
};


int main() {

    return 0;
}
