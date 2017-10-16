/// Source : https://leetcode.com/problems/degree-of-an-array/description/
/// Author : liuyubobobo
/// Time   : 2017-10-15

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>

using namespace std;

// Time Complexity: O(len(nums))
// Space Complexity: O(different number of integer in nums)
class Solution {

public:
    int findShortestSubArray(vector<int>& nums) {

        unordered_map<int, int> freq;
        unordered_map<int, pair<int, int>> pos;
        for(int i = 0 ; i < nums.size() ; i ++)
            if(freq.find(nums[i]) == freq.end()){
                freq[nums[i]] = 1;
                pos[nums[i]] = make_pair(i, i);
            }
            else {
                freq[nums[i]]++;
                pos[nums[i]].second = i;
             }

        int degree = 0;
        for(pair<int, int> p: freq)
            degree = max(degree, p.second);

        int res = nums.size();
        for(pair<int, int> p: freq)
            if(p.second == degree)
                res = min(res, pos[p.first].second - pos[p.first].first + 1);

        return res;
    }

};

int main() {

    int arr0[] = {1};
    vector<int> vec0(arr0, arr0 + sizeof(arr0)/ sizeof(int));
    cout << Solution().findShortestSubArray(vec0) << endl;

    int arr1[] = {1, 2, 2, 3, 1};
    vector<int> vec1(arr1, arr1 + sizeof(arr1)/ sizeof(int));
    cout << Solution().findShortestSubArray(vec1) << endl;

    int arr2[] = {1,2,2,3,1,4,2};
    vector<int> vec2(arr2, arr2 + sizeof(arr2)/ sizeof(int));
    cout << Solution().findShortestSubArray(vec2) << endl;

    return 0;
}