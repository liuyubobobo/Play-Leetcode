#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/// Problem
/**********************************************************************************************
 *
 * Given n non-negative integers a1, a2, ..., an,
 * where each represents a point at coordinate (i, ai).
 * n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
 * Find two lines, which together with x-axis forms a container,
 * such that the container contains the most water.
 *
 * Note: You may not slant the container and n is at least 2.
 **********************************************************************************************/


/// Solution
/***********************************************************************************************
 * Using two pointer technique
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 ************************************************************************************************/

class Solution {
public:
    int maxArea(vector<int>& height) {

        assert( height.size() >= 2 );

        int l = 0, r = height.size() - 1;
        int area = 0;
        while( l < r ){
            area = max( area , min(height[l],height[r])*(r-l) );
            if( height[l] < height[r] )
                l ++;
            else
                r --;
        }

        return area;
    }
};

int main() {

    int nums[] = {1, 1};
    vector<int> nums_vec = vector<int>( nums , nums + sizeof(nums)/sizeof(int));
    cout<<Solution().maxArea( nums_vec )<<endl;

    return 0;
}