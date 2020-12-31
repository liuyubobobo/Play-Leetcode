/// Source : https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
/// Author : liuyubobobo
/// Time   : 2020-05-02

#include <iostream>
#include <vector>
#include <deque>
#include <cmath>

using namespace std;


/// Sliding Window + Sqrt Decomposition
/// Time Complexity: O(n*sqrt(n))
/// Space Complexity: O(n)
class SQRTDecomposition{

private:
    vector<int> data;
    int n;
    int block_size;

    vector<int> minblocks, maxblocks;

public:
    SQRTDecomposition(vector<int>& data) : data(data.begin(), data.end()),
        n(data.size()), block_size((int)ceil(sqrt(n))){

        int cur_min, cur_max;
        for(int i = 0; i < data.size(); i ++){
            if(i % block_size == block_size - 1){
                minblocks.push_back(cur_min);
                maxblocks.push_back(cur_max);
                cur_min = INT_MAX, cur_max = INT_MIN;
            }
            cur_min = min(cur_min, data[i]);
            cur_max = max(cur_max, data[i]);
        }
    }

    int query_min(int l, int r){

        int block_l = l / block_size, block_r = r / block_size;

        int res = data[l];
        if(block_l == block_r){
            for(int i = l + 1; i <= r; i ++)
                res = min(res, data[i]);
        }
        else{
            int limit = (block_l + 1) * block_size;
            for(int i = l + 1; i < limit; i ++)
                res = min(res, data[i]);
            for(int i = block_l + 1; i < block_r; i ++)
                res = min(res, minblocks[i]);
            for(int i = block_r * block_size; i <= r; i ++)
                res = min(res, data[i]);
        }
        return res;
    }

    int query_max(int l, int r){

        int block_l = l / block_size, block_r = r / block_size;

        int res = data[l];
        if(block_l == block_r){
            for(int i = l + 1; i <= r; i ++)
                res = max(res, data[i]);
        }
        else{
            int limit = (block_l + 1) * block_size;
            for(int i = l + 1; i < limit; i ++)
                res = max(res, data[i]);
            for(int i = block_l + 1; i < block_r; i ++)
                res = max(res, maxblocks[i]);
            for(int i = block_r * block_size; i <= r; i ++)
                res = max(res, data[i]);
        }
        return res;
    }
};

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {

        SQRTDecomposition decom(nums);
        int res = 1;
        for(int l = 0, i = 1; i < nums.size(); i ++){
            if(decom.query_max(l, i ) - decom.query_min(l, i) <= limit)
                res = max(res, i - l + 1);
            else while(decom.query_max(l, i) - decom.query_min(l, i) > limit) l ++;
        }
        return res;
    }
};


int main() {

    vector<int> nums1 = {8, 2, 4, 7};
    cout << Solution().longestSubarray(nums1, 4) << endl;
    // 2

    vector<int> nums2 = {10,1,2,4,7,2};
    cout << Solution().longestSubarray(nums2, 5) << endl;
    // 4

    vector<int> nums3 = {4,2,2,2,4,4,2,2};
    cout << Solution().longestSubarray(nums3, 0) << endl;
    // 3

    vector<int> nums4 = {4,10,2,6,1};
    cout << Solution().longestSubarray(nums4, 10) << endl;
    // 5

    return 0;
}
