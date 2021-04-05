/// Source : https://leetcode.com/problems/count-nice-pairs-in-an-array/
/// Author : liuyubobobo
/// Time   : 2021-04-04

#include <iostream>
#include <vector>

using namespace std;


/// Sorting and Mathematics
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    int countNicePairs(vector<int>& nums) {

        for(int i = 0; i < nums.size(); i ++)
            nums[i] -= get_rev(nums[i]);

        sort(nums.begin(), nums.end());
        long long res = 0ll;
        for(int start = 0, i = start + 1; i <= nums.size(); i ++)
            if(i == nums.size() || nums[i] != nums[start]){
                int n = i - start;
                res += (long long)n * (n - 1) / 2ll;
                start = i;
                i = start;
            }
        return res % (long long)(1e9 + 7);
    }

private:
    int get_rev(int x){

        int res = 0;
        while(x){
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
};


int main() {

    return 0;
}
