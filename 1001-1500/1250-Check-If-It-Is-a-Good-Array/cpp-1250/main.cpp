/// Source : https://leetcode.com/problems/check-if-it-is-a-good-array/description/
/// Author : liuyubobobo
/// Time   : 2023-02-14

#include <iostream>
#include <vector>

using namespace std;


/// Math
/// Time Complexity: O(nlog(MAX_NUM))
/// Space Complexity: O(log(MAX_NUM))
class Solution {
public:
    bool isGoodArray(vector<int>& nums) {

        int n = nums.size(), g = nums[0];
        for(int i = 1; i < n && g > 1; i ++)
            g = gcd(g, nums[i]);
        return g == 1;
    }

private:
    int gcd(int a, int b){
        if(a > b) swap(a, b);
        if (a == 0) return b;
        return gcd(b % a, a);
    }
};


int main() {

    return 0;
}
