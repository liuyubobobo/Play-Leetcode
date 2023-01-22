/// Source : https://leetcode.com/problems/minimum-operations-to-make-array-equal-ii/description/
/// Author : liuyubobobo
/// Time   : 2023-01-21

#include <iostream>
#include <vector>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {

        int n = nums1.size();
        if(k == 0){
            for(int i = 0; i < n; i ++)
                if(nums1[i] != nums2[i]) return -1;
            return 0;
        }

        long long a = 0, b = 0;
        for(int i = 0; i < n; i ++){
            if(nums1[i] > nums2[i]){
                long long d = nums1[i] - nums2[i];
                if(d % k != 0) return -1;
                a += d / k;
            }
            else if(nums1[i] < nums2[i]){
                long long d = nums2[i] - nums1[i];
                if(d % k != 0) return -1;
                b += d / k;
            }
        }

        return a == b ? a : -1;
    }
};


int main() {


    return 0;
}
