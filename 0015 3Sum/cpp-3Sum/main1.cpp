/// Source : https://leetcode.com/problems/3sum/
/// Author : liuyubobobo
/// Time   : 2016-12-03


#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <cassert>
#include <stdexcept>

using namespace std;


/// Problem
/*****************************************************************************************************
 *
 * Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 *
 * Note: The solution set must not contain duplicate triplets.
 *
 * For example, given array S = [-1, 0, 1, 2, -1, -4],
 *
 * A solution set is:
 * [
 *  [-1, 0, 1],
 *  [-1, -1, 2]
 * ]
 *****************************************************************************************************/


/// Solution 1
/***********************************************************************************************
 * Use a hashtable to store all the numbers
 * For every a and b, find if c exists
 *
 * To identify the unique triplet,
 * we sort every triplet we found and make the sorted-triplet as a string to be the triplet id
 *
 * Pay attention when all the numbers in a triplet are the same
 *
 * Time Complexity: O(n^2)
 * Space Complexity: O(n)
 *
 * This method will be TLE!
 ************************************************************************************************/

class Solution {

public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        unordered_map<int,int> numbers;
        for( int i = 0 ; i < nums.size() ; i ++ )
            numbers[nums[i]] ++;

        unordered_set<string> triplet_ids;

        vector<vector<int>> res;

        for( int i = 0 ; i < nums.size() ; i ++ )
            for( int j = i + 1 ; j < nums.size() ; j ++ ){
                int c = 0 - nums[i] - nums[j];
                int c_cnt = numbers[c];

                if( c_cnt == 0 )
                    continue;

                if( (c == nums[i] || c == nums[j]) && c_cnt == 1 )
                    continue;

                // tricky
                if( nums[i] == nums[j] && c == nums[i] && c_cnt <= 2 )
                    continue;

                // c != a && c != b
                // c == a || c == b and c_cnt > 1
                // c == a && c == b && c_cnt > 2

                int triplet[] = {nums[i], nums[j], c};
                sort(triplet, triplet + 3 );
                // make the sorted triplet as a string
                // use this string as an id
                string triplet_id = to_string(triplet[0]) + to_string(triplet[1]) + to_string(triplet[2]);

                if( triplet_ids.find(triplet_id) == triplet_ids.end()){
                    triplet_ids.insert( triplet_id );
                    res.push_back( vector<int>(triplet, triplet + 3) );
                }
            }

        return res;
    }
};

int main() {

    int nums[] = {-1, 0, 1, 2, -1, -4};
    vector<int> nums_vec = vector<int>( nums , nums + sizeof(nums)/sizeof(int));

    vector<vector<int>> res = Solution().threeSum( nums_vec );
    for( int i = 0 ; i < res.size() ; i ++ ){
        for( int j = 0 ; j < res[i].size() ; j ++ )
            cout<<res[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}