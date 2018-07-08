/// Source : https://leetcode.com/problems/random-pick-index/description/
/// Author : liuyubobobo
/// Time   : 2018-07-08

#include <iostream>
#include <vector>

using namespace std;


/// Reservor Sampling
/// The detail of Resevoir Sampling can be seen here:
/// https://www.geeksforgeeks.org/reservoir-sampling/
///
/// Attention: Don't use srand in the random problem in Leetcode
/// Since it may lead to WA
/// I think the test code use its own random seed to verify your submitted code
///
/// Time Complexity: init: O(n)
///                  pick: O(n)
/// Space Complexity: O(1)
class Solution {

private:
    vector<int> nums;

public:
    Solution(vector<int> nums) {

        for(int num: nums)
            this->nums.push_back(num);
    }

    int pick(int target) {

        int res = -1;
        int cnt = 0;
        for(int i = 0 ; i < nums.size() ; i ++)
            if(nums[i] == target){
                cnt ++;
                int rnd = rand() % cnt;
                if(rnd == 0)
                    res = i;
            }
        return res;
    }
};


int main() {

    return 0;
}