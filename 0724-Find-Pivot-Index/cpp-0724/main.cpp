/// Source : https://leetcode.com/problems/find-pivot-index/description/
/// Author : liuyubobobo
/// Time   : 2017-11-11

#include <iostream>
#include <vector>

using namespace std;


/// Prefix Sum
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        if(nums.size() == 0)
            return -1;

        vector<int> sum;
        sum.push_back(0);
        for(int num: nums)
            sum.push_back(sum.back() + num);
        sum.push_back(sum.back());

        for(int i = 0 ; i < nums.size() ; i ++)
            if(sum[i] == sum.back() - sum[i+1])
                return i;

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