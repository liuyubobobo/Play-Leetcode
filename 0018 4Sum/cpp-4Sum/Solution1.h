//
// Created by liuyubobobo on 9/27/17.
//

#ifndef CPP_4SUM_SOLUTION1_H
#define CPP_4SUM_SOLUTION1_H

#include <iostream>
#include <vector>
#include <cassert>
#include <stdexcept>

using namespace std;

class Solution1 {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        int n = nums.size();

        vector<vector<int>> res;
        if( n < 4 )
            return res;

        sort( nums.begin() , nums.end() );

        vector<int> one_res(4, 0);
        for( int i = 0 ; i <= n - 4 ; i = nextNumberIndex(nums, i) ) {

            for (int j = i + 1; j <= n - 3; j = nextNumberIndex(nums, j)) {

                int t = target - nums[i] - nums[j];

                if( nums[j+1] + nums[j+2] > t || nums[n-1] + nums[n-2] < t)
                    continue;

                int p1 = j + 1;
                int p2 = nums.size() - 1;

                if (p1 >= p2)
                    break;

                while (p1 < p2) {
                    if (nums[p1] + nums[p2] == t) {
                        one_res[0] = nums[i];
                        one_res[1] = nums[j];
                        one_res[2] = nums[p1];
                        one_res[3] = nums[p2];
                        res.push_back(one_res);

                        p1 = nextNumberIndex(nums, p1);
                        p2 = preNumberIndex(nums, p2);
                    }
                    else if (nums[p1] + nums[p2] < t)
                        p1 = nextNumberIndex(nums, p1);
                    else // nums[p1] + nums[p2] > t
                        p2 = preNumberIndex(nums, p2);
                }
            }
        }

        return res;
    }

private:
    int nextNumberIndex( const vector<int> &nums , int index ){

        for( int i = index + 1 ; i < nums.size() ; i ++ )
            if( nums[i] != nums[index] )
                return i;
        return nums.size();
    }

    int preNumberIndex( const vector<int> &nums , int index ){

        for( int i = index-1 ; i >= 0 ; i -- )
            if( nums[i] != nums[index] )
                return i;
        return -1;
    }
};

#endif //CPP_4SUM_SOLUTION1_H
