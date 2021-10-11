/// Source : https://leetcode.com/problems/two-out-of-three/
/// Author : liuyubobobo
/// Time   : 2021-10-09

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Using Set
/// Time Complexity: O(n1logn1 + n2logn2 + n3logn3)
/// Space Complexity: O(n1 + n2 + n3)
class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {

        set<int> set1(nums1.begin(), nums1.end());
        set<int> set2(nums2.begin(), nums2.end());
        set<int> set3(nums3.begin(), nums3.end());

        vector<int> f(101, 0);
        for(int e: set1) f[e] ++;
        for(int e: set2) f[e] ++;
        for(int e: set3) f[e] ++;

        vector<int> res;
        for(int i = 0; i <= 100; i ++)
            if(f[i] >= 2) res.push_back(i);
        return res;
    }
};


int main() {

    return 0;
}
