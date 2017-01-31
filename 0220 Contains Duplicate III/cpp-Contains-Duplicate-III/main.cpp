/// Source : https://leetcode.com/problems/contains-duplicate-iii/
/// Author : liuyubobobo
/// Time   : 2017-01-26


#include <iostream>
#include <vector>
#include <set>
#include <cassert>
#include <stdexcept>
#include <cmath>

using namespace std;


/// Problem
/************************************************************************************************
 * Given an array of integers,
 * find out whether there are two distinct indices i and j in the array
 * such that the absolute difference between nums[i] and nums[j] is at most t
 * and the absolute difference between i and j is at most k.
 ************************************************************************************************/


/// Solution
/***********************************************************************************************
 * Using sliding window technique to trace every elements in distance k,
 * For each new element, using set's lower_bound and upper_bound to see whether
 * there're two elements satisfy that the absolute difference between them is at most t
 *
 * Time Complexity: O(n)
 * Space Complexity: O(k)
 ************************************************************************************************/

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {

        if( nums.size() <= 1 )
            return false;

        if( k <= 0 )
            return false;

        set<long long> record;
        for( int i = 0 ; i < nums.size() ; i ++ ){

            if( record.size() >= k + 1 )
                record.erase( nums[i-k-1] );

            if( record.lower_bound( (long long)nums[i] - (long long)t ) != record.end() &&
                    fabs(*record.lower_bound( (long long)nums[i] - (long long)t ) - (long long)nums[i]) <= t)
                return true;

            record.insert( nums[i] );
        }

        return false;
    }
};

int main() {

    int nums[] = {-2147483648,-2147483647};
    vector<int> vec( nums, nums + sizeof(nums)/sizeof(int));
    int k = 3;
    int t = 3;

    if( Solution().containsNearbyAlmostDuplicate(vec, k, t) )
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;

    return 0;
}