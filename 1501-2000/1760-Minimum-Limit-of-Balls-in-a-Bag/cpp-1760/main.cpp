/// Source : https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/
/// Author : liuyubobobo
/// Time   : 2021-02-13

#include <iostream>
#include <vector>

using namespace std;


/// Binary Search
/// Time Complexity: O(nlog(max_num))
/// Space Complexity: O(1)
class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {

        int l = 1, r = *max_element(nums.begin(), nums.end()), k = nums.size() + maxOperations;
        while(l < r){
            int mid = (l + r) / 2;
            if(ok(nums, mid, k)) r = mid;
            else l = mid + 1;
        }
        return l;
    }

private:
    bool ok(const vector<int>& nums, int k, int n){

        int sum = 0;
        for(int num: nums)
            sum += num / k + !!(num % k);
        return sum <= n;
    }
};


int main() {

    vector<int> nums1 = {9};
    cout << Solution().minimumSize(nums1, 2) << endl;
    // 3

    vector<int> nums2 = {2, 4, 8, 2};
    cout << Solution().minimumSize(nums2, 4) << endl;
    // 2

    vector<int> nums3 = {7, 17};
    cout << Solution().minimumSize(nums3, 2) << endl;
    // 7

    return 0;
}
