/// Source : https://leetcode.com/problems/minimize-maximum-of-array/
/// Author : liuyubobobo
/// Time   : 2022-10-15

#include <iostream>
#include <vector>

using namespace std;


/// Binary Search
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {

        int n = nums.size();
        vector<long long> data(n);
        for(int i = 0; i < n; i ++) data[i] = nums[i];

        int l = 0, r = 2e9;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(ok(n, data, mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }

private:
    bool ok(int n, vector<long long> nums, long long x){

        for(int i = n - 1; i > 0; i --)
            if(nums[i] > x){
                long long t = nums[i] - x;
                nums[i] -= t;
                nums[i - 1] += t;
            }
        return nums[0] <= x;
    }
};


int main() {

    return 0;
}
