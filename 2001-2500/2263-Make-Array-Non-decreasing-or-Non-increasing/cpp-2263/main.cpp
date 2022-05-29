#include <iostream>
#include <vector>

using namespace std;


class Solution {

private:
    const int MAX_NUM = 1000;

public:
    int convertArray(vector<int>& nums) {

        int n = nums.size(), res = INT_MAX;
        for(int i = 0; i < n; i ++){
            res = min(res, get_inc_arr_by_fix(n, nums, i));
            res = min(res, get_desc_arr_by_fix(n, nums, i));
        }
        return res;
    }

private:
    int get_inc_arr_by_fix(int n, vector<int> nums, int fix_index){

        int res = 0;
        for(int i = fix_index - 1; i >= 0; i --){
            if(nums[i] > nums[i + 1]) res += nums[i] - nums[i + 1], nums[i] = nums[i + 1];
        }
        for(int i = fix_index + 1; i < n; i ++){
            if(nums[i] < nums[i - 1]) res += nums[i - 1] - nums[i], nums[i] = nums[i - 1];
        }
        return res;
    }

    int get_desc_arr_by_fix(int n, vector<int> nums, int fix_index){

        int res = 0;
        for(int i = fix_index - 1; i >= 0; i --){
            if(nums[i] < nums[i + 1]) res += nums[i + 1] - nums[i], nums[i] = nums[i + 1];
        }
        for(int i = fix_index + 1; i < n; i ++){
            if(nums[i] > nums[i - 1]) res += nums[i] - nums[i - 1], nums[i] = nums[i - 1];
        }
        return res;
    }
};


int main() {

    vector<int> nums1 = {0,2,8,0,3};
    cout << Solution().convertArray(nums1) << '\n';
    // 8
    return 0;
}
