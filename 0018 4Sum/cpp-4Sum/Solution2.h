//
// Created by liuyubobobo on 9/27/17.
//

#ifndef CPP_4SUM_SOLUTION2_H
#define CPP_4SUM_SOLUTION2_H

#include <iostream>
#include <vector>
#include <cassert>
#include <stdexcept>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution2 {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        int n = nums.size();

        vector<vector<int>> res;
        if( n < 4 )
            return res;

        sort( nums.begin() , nums.end() );

        unordered_map<int, vector<pair<int, int>>> hashtable;
        for(int i = 0 ; i < n - 1 ; i = nextNumberIndex(nums, i))
            for(int j = i + 1 ; j < n ; j = nextNumberIndex(nums, j))
                hashtable[nums[i]+nums[j]].push_back(make_pair(nums[i], nums[j]));

        vector<int> one_res(4, 0);
        for( int i = 0 ; i <= n - 4 ; i = nextNumberIndex(nums, i) ) {

            for (int j = i + 1; j <= n - 3; j = nextNumberIndex(nums, j)) {

                int t = target - nums[i] - nums[j];
                if( nums[j+1] + nums[j+2] > t || nums[n-1] + nums[n-2] < t)
                    continue;

                if(hashtable.find(t) == hashtable.end())
                    continue;

                one_res[0] = nums[i];
                one_res[1] = nums[j];

                vector<pair<int,int>>::iterator iter =
                        lower_bound(hashtable[t].begin(), hashtable[t].end(), make_pair(nums[j+1], nums[j+1]));
                for(; iter != hashtable[t].end() ; iter ++){
                    one_res[2] = iter->first;
                    one_res[3] = iter->second;
                    res.push_back(one_res);
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

#endif //CPP_4SUM_SOLUTION2_H
