/// Source : https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/
/// Author : liuyubobobo
/// Time   : 2021-05-08

#include <iostream>
#include <vector>

using namespace std;


/// Binary Search
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {

        vector<int> data = nums2;
        reverse(data.begin(), data.end());

        int res = 0;
        for(int i = 0; i < nums1.size(); i ++){

            int j = binary_search(data, 0, (int)nums2.size() - i - 1, nums1[i]);
//            cout << j << endl;
            if(j != -1)
                res = max(res, j - i);
        }
        return res;
    }

private:
    int binary_search(const vector<int>& v, int L, int R, int t){

        if(L > R) return -1;

        int l = L, r = R + 1;
        while(l < r){
            int mid = (l + r) / 2;
            if(v[mid] >= t) r = mid;
            else l = mid + 1;
        }

        if(l > R) return -1;
        return (int)v.size() - 1 - l;
    }
};


int main() {

    vector<int> nums11 = {55, 30, 5, 4, 2}, nums12 = {100, 20, 10, 10, 5};
    cout << Solution().maxDistance(nums11, nums12) << endl;
    // 2

    vector<int> nums21 = {2, 2, 2}, nums22 = {10, 10, 1};
    cout << Solution().maxDistance(nums21, nums22) << endl;
    // 1

    vector<int> nums31 = {30, 29, 19, 5}, nums32 = {25, 25, 25, 25, 25};
    cout << Solution().maxDistance(nums31, nums32) << endl;
    // 2

    vector<int> nums41 = {5, 4}, nums42 = {3, 2};
    cout << Solution().maxDistance(nums41, nums42) << endl;
    // 0

    return 0;
}
