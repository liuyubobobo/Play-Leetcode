/// Source : https://leetcode.com/problems/replace-non-coprime-numbers-in-array/
/// Author : liuyubobobo
/// Time   : 2022-03-05

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


/// Stack
/// Time Complexity: O(nlogn)
/// Space Complexity:O(logn)
class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {

        vector<int> res;
        for(int num: nums){
            int x = num, g;
            while(!res.empty() && (g = gcd(x, res.back())) != 1){
                res.back() *= x / g;
                x = res.back();
                res.pop_back();
            }

            res.push_back(x);
        }
        return res;
    }

private:
    int gcd(int a, int b)
    {
        if(a > b) swap(a, b);
        if (a == 0) return b;
        return gcd(b % a, a);
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << ' '; cout << '\n';
}

int main() {

    vector<int> nums1 = {6,4,3,2,7,6,2};
    print_vec(Solution().replaceNonCoprimes(nums1));
    // 12 7 6

    vector<int> nums2 = {2,2,1,1,3,3,3};
    print_vec(Solution().replaceNonCoprimes(nums2));
    // 2 1 1 3

    vector<int> nums3 = {287,41,49,287,899,23,23,20677,5,825};
    print_vec(Solution().replaceNonCoprimes(nums3));
    // 2009,20677,825

    return 0;
}
