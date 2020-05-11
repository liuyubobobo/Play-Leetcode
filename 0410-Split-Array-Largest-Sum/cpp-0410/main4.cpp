/// Source : https://leetcode.com/problems/split-array-largest-sum/
/// Author : liuyubobobo
/// Time   : 2020-05-11

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Binary Search + Greedy
/// Time Complexity: O(nlog(sum))
/// Space Complexity: O(n)
class Solution {

public:
    int splitArray(vector<int>& nums, int m) {

        long long l = 1ll, r = 0ll;
        for(int num: nums) r += num;

        while(l < r){
            long long mid = (l + r) / 2;
            if(ok(nums, m, mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }

private:
    bool ok(const vector<int>& nums, int m, long long len){

        if(*max_element(nums.begin(), nums.end()) > len) return false;

        int res = 1;
        long long cur = 0ll;
        for(int e: nums){
            if(cur + e > len){
                res ++;
                cur = e;
            }
            else cur += e;
        }
        return res <= m;
    }
};


int main() {

    vector<int> nums1 = {7, 2, 5, 10, 8};
    cout << Solution().splitArray(nums1, 2) << endl;
    // 18

    vector<int> nums2 = {1,2147483647};
    cout << Solution().splitArray(nums2, 2) << endl;
    // 2147483647

    return 0;
}
