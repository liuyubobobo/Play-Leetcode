/// Source : https://leetcode.com/problems/contains-duplicate-ii/
/// Author : liuyubobobo
/// Time   : 2017-01-26


#include <iostream>
#include <vector>
#include <unordered_set>
#include <cassert>
#include <stdexcept>

using namespace std;


/// Problem
/************************************************************************************************
 * Given an array of integers and an integer k,
 * find out whether there are two distinct indices i and j in the array
 * such that nums[i] = nums[j]
 * and the absolute difference between i and j is at most k.
 ************************************************************************************************/


/// Solution
/***********************************************************************************************
 * Using the sliding window technique to trace the elements in distance k,
 * and using a hashtable to see whether there's a equal elements
 *
 * Time Complexity: O(n)
 * Space Complexity: O(k)
 ************************************************************************************************/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        if( nums.size() <= 1 )
            return false;

        if( k <= 0 )
            return false;

        unordered_set<int> record;
        for( int i = 0 ; i < nums.size() ; i ++ ){
            // record中最多包含从 a 到 a + k 共 k + 1个元素
            if( record.size() >= k + 1 )
                record.erase(nums[i-k-1]);

            if( record.find( nums[i] ) != record.end() )
                return true;
            else
                record.insert( nums[i] );
        }


        return false;
    }
};

int main() {

    int nums[] = {1, 2, 1};
    vector<int> vec(nums, nums+sizeof(nums)/sizeof(int));
    int k = 1;

    if( Solution().containsNearbyDuplicate(vec,0) )
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;

    return 0;
}