/// Source : https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/
/// Author : liuyubobobo
/// Time   : 2016-12-26
#include <iostream>
#include <vector>

using namespace std;

/// Ad-Hoc
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int i = 0;
        int j = 0;
        while(j < nums.size()){
            int k = nextIndex(nums, j);
            int len = min( 2, k-j);
            for(int ii = 0 ; ii < len ; ii ++)
                nums[i+ii] = nums[j];
            i += len;
            j = k;
        }

        return i;
    }

private:
    int nextIndex(const vector<int>& nums, int index){
        for(int i = index ; i < nums.size() ; i ++)
            if(nums[i] != nums[index])
                return i;
        return nums.size();
    }
};


int main() {

    vector<int> nums1 = {1, 1, 1, 2, 2, 3};
    cout << Solution().removeDuplicates(nums1) << endl;

    return 0;
}