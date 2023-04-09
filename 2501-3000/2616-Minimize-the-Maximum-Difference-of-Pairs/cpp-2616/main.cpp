/// Source : https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/description/
/// Author : liuyubobobo
/// Time   : 2023-04-09

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Binary Search
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {

        int n = nums.size();
        sort(nums.begin(), nums.end());

        int l = 0, r = nums.back() - nums.front();
        while(l < r){
            int mid = (l + r) / 2;
            if(ok(n, nums, p, mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }

private:
    bool ok(int n, const vector<int>& nums, int p, int d){

        int i = 0, cnt = 0;
        while(i + 1 < n){
            if(nums[i + 1] - nums[i] <= d) cnt ++, i += 2;
            else i ++;
        }
        return cnt >= p;
    }
};


int main() {

    return 0;
}
