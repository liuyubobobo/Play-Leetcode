/// Source : https://leetcode.com/problems/majority-element/description/
/// Author : liuyubobobo
/// Time   : 2017-11-14

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

/// Using Randomization
/// Time Complexity: Worst: O(infinity)
///                  Average: O(n)
/// Space Complexity: O(1)
class Solution {

public:
    int majorityElement(vector<int>& nums) {

        assert(nums.size() > 0);

        srand(time(NULL));

        // The expectation to run this loop is 2
        // see the proof in https://leetcode.com/problems/majority-element/solution/#approach-4-randomization-accepted
        while(true){
            int randIndex = rand()%nums.size();
            if(occurance(nums, nums[randIndex]) > nums.size()/2)
                return nums[randIndex];
        }
    }

private:
    int occurance(const vector<int>& nums, int target){
        int cnt = 0;
        for(int num: nums)
            if(num == target)
                cnt ++;
        return cnt;
    }
};

int main() {

    int nums[1] = {1};
    vector<int> vec(nums, nums + 1);
    cout << Solution().majorityElement(vec) << endl;
    return 0;
}