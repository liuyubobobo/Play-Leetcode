/// Source : https://leetcode.com/problems/sliding-subarray-beauty/description/
/// Author : liuyubobobo
/// Time   : 2023-04-23

#include <iostream>
#include <vector>

using namespace std;


/// Sliding Window
/// Time Complexity: O(n * |max_num - min_num|)
/// Space Complexity: O(|max_num - min_num|)
class Solution {

private:
    const int OFFSET = 50;

public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {

        vector<int> f(101, 0);

        for(int i = 0; i < k - 1; i ++) f[nums[i] + OFFSET] ++;

        vector<int> res;
        for(int i = k - 1; i < nums.size(); i ++){
            f[nums[i] + OFFSET] ++;

            res.push_back(min(0, get_kth(f, x)));
            f[nums[i - (k - 1)] + OFFSET] --;
        }
        return res;
    }

private:
    int get_kth(vector<int>& f, int k){
        int sum = 0;
        for(int i = 0; i <= 100; i ++){
            sum += f[i];
            if(sum >= k) return i - OFFSET;
        }
        return -1;
    }
};


int main() {

    return 0;
}
