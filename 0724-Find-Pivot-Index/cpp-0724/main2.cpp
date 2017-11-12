/// Source : https://leetcode.com/problems/find-pivot-index/description/
/// Author : liuyubobobo
/// Time   : 2017-11-12

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Prefix Sum with just One Variable
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        if(nums.size() == 0)
            return -1;

        int sum = accumulate(nums.begin(), nums.end(), 0);

        int leftSum = 0;
        for(int i = 0 ; i < nums.size() ; i ++)
            if(leftSum == sum - leftSum - nums[i])
                return i;
            else
                leftSum += nums[i];

        return -1;
    }
};

void printVec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}


int main() {

    int nums1[6] = {1, 7, 3, 6, 5, 6};
    vector<int> vec1(nums1, nums1 + 6);
    cout << Solution().pivotIndex(vec1) << endl;
    // 3

    // ---

    int nums2[1] = {666};
    vector<int> vec2(nums2, nums2 + 1);
    cout << Solution().pivotIndex(vec2) << endl;
    // 0

    return 0;
}