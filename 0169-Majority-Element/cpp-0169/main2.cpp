/// Source : https://leetcode.com/problems/majority-element/description/
/// Author : liuyubobobo
/// Time   : 2017-11-14

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>

using namespace std;

/// Using Hash Map
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

public:
    int majorityElement(vector<int>& nums) {

        assert(nums.size() > 0);

        unordered_map<int, int> records;
        for(int num: nums)
            records[num] ++;

        for(pair<int, int> record: records)
            if(record.second > nums.size()/2)
                return record.first;

        throw invalid_argument("No Solution!");
    }
};

int main() {

    return 0;
}