/// Source : https://leetcode.com/problems/contains-duplicate-iii/description/
/// Author : liuyubobobo
/// Time   : 2017-11-15

#include <iostream>
#include <vector>
#include <set>
#include <cassert>
#include <stdexcept>
#include <cmath>

using namespace std;

// Using Tree Set
// Time Complexity: O(nlogk)
// Space Complexity: O(k)
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {

        if(t < 0)
            return false;

        set<long long> record;
        for(int i = 0 ; i < nums.size() ; i ++){

            if(record.lower_bound((long long)nums[i] - (long long)t) != record.end() &&
                *record.lower_bound((long long)nums[i] - (long long)t ) <= (long long)nums[i] + (long long)t)
                return true;

            record.insert(nums[i]);

            if(record.size() == k + 1)
                record.erase( nums[i-k] );
        }

        return false;
    }
};


void printBool(bool b){
    cout << (b ? "True" : "False") << endl;
}

int main() {

    int nums[] = {-2147483648, -2147483647};
    vector<int> vec(nums, nums + sizeof(nums)/sizeof(int));
    int k = 3;
    int t = 3;

    printBool(Solution().containsNearbyAlmostDuplicate(vec, k, t));

    return 0;
}