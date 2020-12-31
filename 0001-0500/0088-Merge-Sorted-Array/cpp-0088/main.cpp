/// Source : https://leetcode.com/problems/merge-sorted-array/
/// Author : liuyubobobo
/// Time   : 2019-02-07

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/// Sorting
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        assert(nums1.size() == m + n && nums2.size() == n);

        for(int i = 0; i < n ; i ++ )
            nums1[m + i] = nums2[i];

        sort(nums1.begin(), nums1.end());
    }
};


void print_vec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    vector<int> nums1 = {1, 3, 5, 7};
    int m = nums1.size();

    vector<int> nums2 = {2, 4, 6};
    int n = nums2.size();

    for( int i = 0 ; i < nums2.size() ; i ++ )
        nums1.push_back(0);

    Solution().merge(nums1, m, nums2, n);
    print_vec(nums1);

    return 0;
}