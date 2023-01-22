/// Source : https://leetcode.com/problems/minimum-common-value/description/
/// Author : liuyubobobo
/// Time   : 2023-01-21

#include <iostream>
#include <vector>

using namespace std;


/// Two Pointers
/// Time Complexity: O(|nums1| + |nums2|)
/// Space Complexity: O(1)
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {

        int i = 0, j = 0;
        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] == nums2[j]) return nums1[i];
            else if(nums1[i] < nums2[j]) i ++;
            else j ++;
        }
        return -1;
    }
};


int main() {

    return 0;
}
