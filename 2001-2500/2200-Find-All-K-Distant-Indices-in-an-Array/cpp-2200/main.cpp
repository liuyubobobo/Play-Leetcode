/// Source : https://leetcode.com/problems/find-all-k-distant-indices-in-an-array/
/// Author : liuyubobobo
/// Time   : 2022-03-12

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// BruteForce
/// Time Complexity: O(n^2)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {

        int n = nums.size();
        vector<int> res;
        for(int i = 0; i < n; i ++)
            for(int j = max(i - k, 0); j <= min(i + k, n - 1); j ++)
                if(nums[j] == key){
                    res.push_back(i);
                    break;
                }
        return res;
    }
};


int main() {

    return 0;
}
