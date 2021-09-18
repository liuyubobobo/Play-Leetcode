/// Source : https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/
/// Author : liuyubobobo
/// Time   : 2021-09-18

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Sorting + Using HashMap
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());
        int res = 0;
        unordered_map<int, int> f;
        for(int e: nums){
            if(f.count(e - k)) res += f[e - k];
            f[e] ++;
        }
        return res;
    }
};


int main() {

    return 0;
}
