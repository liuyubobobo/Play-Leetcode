/// Source : https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/description/
/// Author : liuyubobobo
/// Time   : 2023-02-20

#include <iostream>
#include <vector>

using namespace std;


/// Merge
/// Time Complexity: O(n1 + n2)
/// Space Complexity: O(1)
class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {

        vector<vector<int>> res;
        int n1 = nums1.size(), n2 = nums2.size();
        for(int i = 0, j = 0; i < n1 || j < n2;){
            if(i == n1) res.push_back(nums2[j++]);
            else if(j == n2) res.push_back(nums1[i++]);
            else if(nums1[i][0] < nums2[j][0]) res.push_back(nums1[i++]);
            else if(nums1[i][0] > nums2[j][0]) res.push_back(nums2[j++]);
            else res.push_back({nums1[i][0], nums1[i ++][1] + nums2[j ++][1]});
        }
        return res;
    }
};


int main() {

    return 0;
}
