/// Source : https://leetcode.com/problems/next-greater-element-iii/submissions/
/// Author : liuyubobobo
/// Time   : 2020-12-24

#include <iostream>
#include <vector>

using namespace std;


/// next permutation
/// Time Complexity: O(logn)
/// Space Complexity: O(logn)
class Solution {
public:
    int nextGreaterElement(int n) {

        vector<int> v;
        while(n) v.push_back(n % 10), n /= 10;
        reverse(v.begin(), v.end());

        if(!next_permutation(v.begin(), v.end())) return -1;

        long long x = 0ll;
        for(int e: v) x = x * 10 + e;
        return x <= INT_MAX ? x : -1;
    }
};


int main() {

    return 0;
}
