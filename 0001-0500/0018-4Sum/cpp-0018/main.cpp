/// Source : https://leetcode.com/problems/4sum/
/// Author : liuyubobobo
/// Time   : 2016-12-06
/// Updated: 2023-07-14

#include <iostream>
#include <vector>
#include <cassert>
#include <stdexcept>

using namespace std;


/// Two pointers
/// Sort the array first.
/// For every different number a and b, try to find a pair (c, d), which a + b + c + d == 0
/// Using this way, we don't need to see whether the triplet is a repeated one
///
/// Time Complexity: O(nlogn) + O(n^3)
/// Space Complexity: O(1)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        int n = nums.size();

        vector<vector<int>> res;
        if(n < 4)
            return res;

        sort(nums.begin(), nums.end());
        for(int i = 0 ; i <= n - 4 ; i = nextNumberIndex(nums, i))
            for (int j = i + 1; j <= n - 3; j = nextNumberIndex(nums, j)) {

               long long t = 0ll + target - nums[i] - nums[j];

                if(nums[j+1] + nums[j+2] > t || nums[n-1] + nums[n-2] < t)
                    continue;

                int p1 = j + 1;
                int p2 = nums.size() - 1;
                if (p1 >= p2)
                    break;

                while (p1 < p2) {
                    if (nums[p1] + nums[p2] == t) {
                        res.push_back({nums[i], nums[j], nums[p1], nums[p2]});

                        p1 = nextNumberIndex(nums, p1);
                        p2 = preNumberIndex(nums, p2);
                    }
                    else if (nums[p1] + nums[p2] < t)
                        p1 = nextNumberIndex(nums, p1);
                    else // nums[p1] + nums[p2] > t
                        p2 = preNumberIndex(nums, p2);
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