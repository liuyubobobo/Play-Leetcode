/// Source : https://leetcode.com/problems/single-number/
/// Author : liuyubobobo
/// Time   : 2016-12-05

#include <iostream>
#include <vector>
#include <unordered_set>
#include <cassert>

using namespace std;


/// Using hashtable to find the one
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int singleNumber(vector<int>& nums) {

        assert(nums.size()%2 == 1);

        unordered_set<int> hashtable;
        for(int i = 0 ; i < nums.size() ; i ++)
            if(hashtable.find(nums[i]) == hashtable.end())
                hashtable.insert(nums[i]);
            else
                hashtable.erase(nums[i]);

        assert(hashtable.size() == 1);
        return *hashtable.begin();
    }
};


int main() {

    vector<int> nums = {0, 0, 1, 1, 2};
    cout << Solution().singleNumber(nums) << endl;

    return 0;
}