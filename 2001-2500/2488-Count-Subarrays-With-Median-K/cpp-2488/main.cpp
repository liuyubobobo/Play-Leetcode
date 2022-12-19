/// Source : https://leetcode.com/problems/count-subarrays-with-median-k/
/// Author : liuyubobobo
/// Time   : 2022-12-18

#include <iostream>
#include <vector>
#include <map>
#include <numeric>

using namespace std;


/// Median Classic
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {

        int n = nums.size();

        vector<int> data(n, 0);
        int kpos = -1;
        for(int i = 0; i < n; i ++) {
            if (nums[i] < k) data[i] = -1;
            else if (nums[i] > k) data[i] = 1;
            else kpos = i;
        }

        map<int, int> f;
        f[0] = 1;
        int cur = 0;
        for(int i = kpos + 1; i < n; i ++){
            cur += data[i];
            f[cur] ++;
        }

        int lsum = accumulate(data.begin(), data.begin() + kpos + 1, 0);
        int res = 0;
        for(int l = 0; l <= kpos; l ++){
            auto iter = f.find(-lsum);
            if(iter != f.end()) res += iter->second;
            iter = f.find(1-lsum);
            if(iter != f.end()) res += iter->second;
            lsum -= data[l];
        }
        return res;
    }
};


int main() {

    return 0;
}
