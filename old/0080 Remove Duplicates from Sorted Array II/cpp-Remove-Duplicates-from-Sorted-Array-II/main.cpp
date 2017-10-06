#include <iostream>
#include <vector>

using namespace std;


/// Problem
/***********************************************************************************
 *
 * Follow up for "Remove Duplicates":
 * What if duplicates are allowed at most twice?
 *
 * For example,
 * Given sorted array nums = [1,1,1,2,2,3],
 * Your function should return length = 5,
 * with the first five elements of nums being 1, 1, 2, 2 and 3.
 * It doesn't matter what you leave beyond the new length.
 **************************************************************************************/


/// Solution
/***********************************************************************************************
 * Same algorithm for Remove Duplicates
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 ************************************************************************************************/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int i = 0;
        int j = 0;
        while( j < nums.size() ){
            int k = nextIndex( nums, j );
            int len = min( 2, k-j);
            for( int ii = 0 ; ii < len ; ii ++ )
                nums[i+ii] = nums[j];
            i += len;
            j = k;
        }

        return i;
    }

private:
    int nextIndex( const vector<int>& nums, int index ){
        for( int i = index ; i < nums.size() ; i ++ )
            if( nums[i] != nums[index] )
                return i;
        return nums.size();
    }
};

int main() {

    int nums[] = {1, 1, 1, 2, 2, 3};
    vector<int> nums_vec = vector<int>( nums , nums + sizeof(nums)/sizeof(int));

    cout<<Solution().removeDuplicates( nums_vec )<<endl;

    return 0;
}