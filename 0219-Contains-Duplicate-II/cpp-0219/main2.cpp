/// Source : https://leetcode.com/problems/contains-duplicate-ii/description/
/// Author : liuyubobobo
/// Time   : 2019-04-10

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/// Using Hash Map
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        if(nums.size() <= 1)
            return false;

        if(k <= 0)
            return false;

        unordered_map<int, int> record;
        record[nums[0]] = 0;
        for(int i = 1 ; i < nums.size() ; i ++){

            if(record.count(nums[i]) && i - record[nums[i]] <= k)
                return true;

            record[nums[i]] = i;
        }

        return false;
    }
};


void print_bool(bool b){
    cout << (b ? "True" : "False") << endl;
}

int main() {

    vector<int> nums = {1, 2, 1};
    int k = 1;

    print_bool(Solution().containsNearbyDuplicate(nums, k));

    return 0;
}