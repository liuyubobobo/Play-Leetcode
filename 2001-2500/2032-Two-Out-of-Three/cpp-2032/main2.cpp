/// Source : https://leetcode.com/problems/two-out-of-three/
/// Author : liuyubobobo
/// Time   : 2021-10-10

#include <iostream>
#include <vector>

using namespace std;


/// Using Array instead of Set
/// Time Complexity: O(n1 + n2 + n3)
/// Space Complexity: O(n1 + n2 + n3)
class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {

        vector<bool> f1(101, false), f2(101, false), f3(101, false);
        for(int e: nums1) f1[e] = true;
        for(int e: nums2) f2[e] = true;
        for(int e: nums3) f3[e] = true;

        vector<int> res;
        for(int i = 0; i <= 100; i ++)
            if(f1[i] + f2[i] + f3[i] >= 2) res.push_back(i);
        return res;
    }
};


int main() {

    return 0;
}
