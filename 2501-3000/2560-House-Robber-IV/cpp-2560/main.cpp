/// Source : https://leetcode.com/problems/house-robber-iv/description/
/// Author : liuyubobobo
/// Time   : 2023-02-05

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Binary Search
/// Time Complexity: O(nlog(max_num))
/// Space Complexity: O(1)
class Solution {
public:
    int minCapability(vector<int>& nums, int k) {

        int n = nums.size();
        int l = 0, r = *max_element(nums.begin(), nums.end());
        while(l < r){
            int mid = (l + r) / 2;
            if(ok(n, nums, mid, k)) r = mid;
            else l = mid + 1;
        }
        return l;
    }

private:
    bool ok(int n, const vector<int>& nums, int v, int k){

        int cnt = 0;
        for(int i = 0; i < n; i ++)
            if(nums[i] <= v) cnt ++, i ++;
        return cnt >= k;
    }
};


int main() {


    return 0;
}
