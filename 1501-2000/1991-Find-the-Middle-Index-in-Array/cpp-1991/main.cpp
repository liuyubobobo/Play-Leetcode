/// Source : https://leetcode.com/problems/find-the-middle-index-in-array/
/// Author : liuyubobobo
/// Time   : 2021-09-05

#include <iostream>
#include <vector>

using namespace std;


/// Presum
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {

        int n = nums.size();
        vector<int> presum(n + 1, 0);
        for(int i = 0; i < nums.size(); i ++)
            presum[i + 1] = presum[i] + nums[i];

        for(int i = 0; i < n; i ++)
            if(presum[i] == presum[n] - presum[i + 1]) return i;
        return -1;
    }
};


int main() {

    return 0;
}
