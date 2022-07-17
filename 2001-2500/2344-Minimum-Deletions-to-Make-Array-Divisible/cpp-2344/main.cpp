/// Source : https://leetcode.com/problems/minimum-deletions-to-make-array-divisible/
/// Author : liuyubobobo
/// Time   : 2022-07-16

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Sorting and Greedy
/// Time Complexity: O(nlog(max(numsDivide)) + nlogn)
/// Space Complexity: O(log(max(numsDivide)))
class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {

        int t = numsDivide[0];
        for(int i = 1; i < numsDivide.size(); i ++)
            t = gcd(min(t, numsDivide[i]), max(t, numsDivide[i]));

        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i ++)
            if(t % nums[i] == 0) return i;
        return -1;
    }

private:
    int gcd(int a, int b){
        if (a == 0) return b;
        return gcd(b % a, a);
    }
};


int main() {

    return 0;
}
