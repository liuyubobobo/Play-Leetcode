/// Source : https://leetcode.com/problems/missing-number/description/
/// Author : liuyubobobo
/// Time   : 2017-11-10

#include <iostream>
#include <vector>
#include <unordered_set>
#include <cassert>

using namespace std;


/// HashSet
/// Time Complexity:  O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> records;
        for(int num: nums)
            records.insert(num);
        for(int i = 0 ; i <= nums.size() ; i ++)
            if(records.find(i) == records.end())
                return i;
        assert(false), "You should never reach here is the answer exist:)";
    }
};

int main() {

    int nums[3] = {0, 1, 3};
    vector<int> vec(nums, nums + 3);
    cout << Solution().missingNumber(vec) << endl;

    return 0;
}