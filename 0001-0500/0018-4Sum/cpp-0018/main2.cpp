/// Source : https://leetcode.com/problems/4sum/
/// Author : liuyubobobo
/// Time   : 2017-09-27
/// Updated: 2023-07-14

#include <iostream>
#include <vector>
#include <cassert>
#include <stdexcept>
#include <unordered_map>
#include <algorithm>

using namespace std;


/// Using hash table
/// Sort the array first.
/// Store every different c + d == t first
/// For every different number a and b, try to find a pair (c, d), which a + b + c + d == 0
///
/// Time Complexity: O(nlogn) + O(n^2) + O(n^3)
/// Space Complexity: O(n^2)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        int n = nums.size();

        vector<vector<int>> res;
        if(n < 4)
            return res;

        sort(nums.begin() , nums.end());

        unordered_map<int, vector<pair<int, int>>> hashtable;
        for(int i = 0 ; i < n - 1 ; i = nextNumberIndex(nums, i))
            for(int j = i + 1 ; j < n ; j = nextNumberIndex(nums, j))
                hashtable[nums[i]+nums[j]].push_back(make_pair(nums[i], nums[j]));

        for( int i = 0 ; i <= n - 4 ; i = nextNumberIndex(nums, i) )
            for (int j = i + 1; j <= n - 3; j = nextNumberIndex(nums, j)) {

                long long t = 0ll + target - nums[i] - nums[j];
                if( nums[j+1] + nums[j+2] > t || nums[n-1] + nums[n-2] < t)
                    continue;

                if(hashtable.find(t) == hashtable.end())
                    continue;

                vector<pair<int,int>>::iterator iter =
                        lower_bound(hashtable[t].begin(), hashtable[t].end(), make_pair(nums[j+1], nums[j+1]));
                for(; iter != hashtable[t].end() ; iter ++)
                    res.push_back({nums[i], nums[j], iter->first, iter->second});
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


void print_vec(const vector<vector<int>>& vec){
    for(const vector<int>& v: vec){
        for(int e: v)
            cout << e << " ";
        cout << endl;
    }
}

int main() {

    vector<int> nums1 = {1, 0, -1, 0, -2, 2};
    int target1 = 0;
    print_vec(Solution().fourSum(nums1, target1));

    return 0;
}