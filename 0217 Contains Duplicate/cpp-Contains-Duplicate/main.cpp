/// Source : https://leetcode.com/problems/contains-duplicate/
/// Author : liuyubobobo
/// Time   : 2017-01-18

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

/// Problem
/********************************************************************************************************
 *
 * Given an array of integers, find if the array contains any duplicates.
 * Your function should return true if any value appears at least twice in the array,
 * and it should return false if every element is distinct.
 ********************************************************************************************************/


/// Solution
/***********************************************************************************************
 * Using HashTable
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 ************************************************************************************************/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        unordered_set<int> record;
        for( int i = 0 ; i < nums.size() ; i ++ )
            if( record.find( nums[i] ) == record.end() )
                record.insert( nums[i] );
            else
                return true;

        return false;
    }
};

int main() {

    int nums[] = {0, 0, 1};
    vector<int> vec( nums, nums + sizeof(nums)/sizeof(int));

    cout << Solution().containsDuplicate( vec )<<endl;

    return 0;
}