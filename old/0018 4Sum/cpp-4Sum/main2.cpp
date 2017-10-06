/// Source : https://leetcode.com/problems/4sum/
/// Author : liuyubobobo
/// Time   : 2017-09-27

/***********************************************************************************************
 * Using hash table
 *
 * Sort the array first.
 * Store every different c + d == t first
 * For every different number a and b, try to find a pair (c, d), which a + b + c + d == 0
 *
 * Time Complexity: O(nlogn) + O(n^2) + O(n^2*logn)
 * Space Complexity: O(n^2)
 ************************************************************************************************/


#include <iostream>
#include <vector>
#include <cassert>
#include <stdexcept>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
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

int main() {

    int nums[] = {1, 0, -1, 0, -2, 2};
    vector<int> nums_vec = vector<int>( nums , nums + sizeof(nums)/sizeof(int));
    int target = 0;

    vector<vector<int>> res = Solution().fourSum( nums_vec , target );
    for( int i = 0 ; i < res.size() ; i ++ ){
        for( int j = 0 ; j < res[i].size() ; j ++ )
            cout<<res[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}