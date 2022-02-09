/// Source : https://leetcode.com/problems/k-diff-pairs-in-an-array/
/// Author : liuyubobobo
/// Time   : 2022-02-08

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Using Map
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {

        multiset<int> left;
        set<pair<int, int>> record;
        for(int e: nums) left.insert(e);

        for(int i = (int)nums.size() - 1; i >= 0; i --){
            left.erase(left.find(nums[i]));
            int a = nums[i] - k, b = nums[i], c = nums[i] + k;
            if(left.count(a)) record.insert({min(a, b), max(a, b)});
            if(left.count(c)) record.insert({min(b, c), max(b, c)});
        }
        return record.size();
    }
};


int main() {

    vector<int> nums1 = {3, 1, 4, 1, 5};
    cout << Solution().findPairs(nums1, 2) << endl;
    // 2

    vector<int> nums2 = {1, 3, 1, 5, 4};
    cout << Solution().findPairs(nums2, 0) << endl;
    // 1

    vector<int> nums3 = {1,2,4,4,3,3,0,9,2,3};
    cout << Solution().findPairs(nums3, 3) << endl;
    // 2

    return 0;
}
