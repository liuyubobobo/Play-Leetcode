/// Source : https://leetcode.com/problems/divide-array-into-increasing-sequences/
/// Author : liuyubobobo
/// Time   : 2019-07-13

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Using HashMap to calculate freq
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    bool canDivideIntoSubsequences(vector<int>& nums, int K) {

        unordered_map<int, int> freq;
        int count = 0;
        for(int e: nums){
            freq[e] ++;
            count = max(count, freq[e]);
        }

        return nums.size() / count >= K;
    }
};


int main() {

    return 0;
}