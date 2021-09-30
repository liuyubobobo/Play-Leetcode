/// Source : https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/
/// Author : liuyubobobo
/// Time   : 2021-09-29

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Using Map
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {

        map<int, int> map;
        map[0] = -1;

        int presum = 0, res = 0;
        for(int i = 0; i < nums.size(); i ++){
            presum += nums[i];
            if(map.count(presum - k)) res = max(res, i - map[presum - k]);
            if(!map.count(presum)) map[presum] = i;
        }
        return res;
    }
};


int main() {

    return 0;
}
