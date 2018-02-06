/// Source : https://leetcode.com/problems/3sum/
/// Author : liuyubobobo
/// Time   : 2016-12-03

#include <iostream>
#include <vector>
#include <cassert>
#include <stdexcept>

using namespace std;


/// Using two pointer technique
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {

public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> res;

        int index = 0;
        while( index < nums.size() ){

            if( nums[index] > 0 )
                break;

            int bindex = index + 1;
            int cindex = nums.size()-1;
            while( bindex < cindex) {

                if (nums[bindex] + nums[cindex] == -nums[index]) {
                    res.push_back({nums[index], nums[bindex], nums[cindex]});

                    // continue to look for other pairs
                    bindex = next_num_index( nums, bindex );
                    cindex = pre_num_index( nums, cindex);
                }
                else if (nums[bindex] + nums[cindex] < -nums[index])
                    bindex = next_num_index( nums, bindex );
                else //nums[bindex] + nums[cindex] > -nums[index]
                    cindex = pre_num_index( nums, cindex);
            }

            index = next_num_index( nums , index );
        }

        return res;
    }

private:
    int next_num_index( const vector<int> &nums, int cur ){

        for( int i = cur + 1; i < nums.size() ; i ++ )
            if( nums[i] != nums[cur] )
                return i;
        return nums.size();
    }

    int pre_num_index( const vector<int> &nums, int cur){

        for( int i = cur - 1; i >= 0 ; i -- )
            if( nums[i] != nums[cur] )
                return i;
        return -1;
    }
};

int main() {

    vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res = Solution().threeSum(nums1);
    for( int i = 0 ; i < res.size() ; i ++ ){
        for( int j = 0 ; j < res[i].size() ; j ++ )
            cout<<res[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}